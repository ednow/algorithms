from utils.page.combiner import Combiner, Configuration, Replace, Chain, Data, Prefix, Suffix
from utils.markdownTools.table import TableReader
import os
import re


# 合并readme到一个文件
def combine_readme():
    # cpp 代码段处理
    cppChain = Chain(Prefix("\n\n<details><summary>代码详情</summary>\n\n```cpp\n"), Suffix("\n```\n\n</details>\n\n"))
    # python 代码段的处理
    pythonChain = Chain(Prefix("\n\n<details><summary>代码详情</summary>\n\n```python\n"), Suffix("\n```\n\n</details>\n\n"))
    # 测试数据的代码段
    dataChain = Chain(Prefix("\n\n<details><summary>代码详情</summary>\n\n```json\n"), Suffix("\n```\n\n</details>\n\n"))
    pta_root_dir = os.path.join("PTA")

    # 将总表中的tag读入并写进合并文件里面
    with open(os.path.join(pta_root_dir, "README.md"), "r", encoding="utf-8") as f:
        table = TableReader(re.sub(r"## .*?\n(.*?)##.*", r"\1", f.read(), flags=re.DOTALL).strip()).to_pandas()

    # table.index.astype(int)
    table.index = table["题目编号"].astype(int)

    # 新建一个combiner
    prefix = "---\ntitle: pta\netoc: true\ndate: 2021-08-25 18:09:32\nmathjax: true\ntags:\n---\n\n"
    config = Configuration().add_post_processor(Prefix(prefix))
    config.set_joiner("\n\n")
    combine = Combiner(config)

    # 加内容到combiner中
    for subdir in os.listdir(pta_root_dir):
        match_str = re.match(r"PTA(\d{4})", subdir)
        if match_str is not None:
            # 读入markdown
            with open(os.path.join(pta_root_dir, subdir, "README.md"), "r", encoding="utf-8") as f:
                key = int(match_str.group(1))
                string = f.read()
                hr = "\n+ "
                string = (
                    combine
                    .add_next_string(string)
                    # 为所有的总结加上正确的pta题号
                    .preprocess(Replace(r"^# \w*\n", f"# PTA{key}总结\n"))
                    # 将总表的tag加到合并的内容里面
                    .preprocess(Replace(r"(## 考点)(.*?##)",
                                        r'\1' + hr + f"{hr.join(table.loc[key, 'tag'].split(','))}" + r'\2'))
                    .set_key(key)
                )
            # 读入代码和测试数据
            for codeType, chain in zip(["py", "cpp", "json"], [pythonChain, cppChain, dataChain]):
                for codeFile in filter(lambda x: x.endswith(codeType), os.listdir(os.path.join(pta_root_dir, subdir))):
                    with open(os.path.join(pta_root_dir, subdir, codeFile), "r", encoding="utf-8") as f:
                        string += Prefix(f"## {codeFile}\n").do_preprocess(chain(Data(f.read())))

    # 写入文件
    dir_to_store = "page"
    if not os.path.exists(dir_to_store):
        os.makedirs(dir_to_store)
    output_file = "pta.md"
    with open(os.path.join(dir_to_store, output_file), "w", encoding="utf-8") as f:
        f.write(combine.combine())


if __name__ == '__main__':
    combine_readme()