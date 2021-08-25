from utils.page.combiner import Combiner, Configuration, Replace
import os
import re


# 合并readme到一个文件
def combine_readme():
    config = Configuration()
    config.set_joiner("\n\n")
    combine = Combiner(config)
    pta_root_dir = os.path.join("PTA")
    for file in os.listdir(pta_root_dir):
        match_str = re.match(r"PTA(\d{4})", file)
        if match_str is not None:
            with open(os.path.join(pta_root_dir, file, "README.md"), "r", encoding="utf-8") as f:
                key = int(match_str.group(1))
                string = f.read()
                string = re.sub(r"^# \w*\n", f"# PTA{key}总结\n", string)
                combine.add_next_string(string).set_key(key)
    dir_to_store = "page"
    if not os.path.exists(dir_to_store):
        os.makedirs(dir_to_store)
    output_file = "readme_all_in_one.md"
    with open(os.path.join(dir_to_store, output_file), "w", encoding="utf-8") as f:
        f.write(combine.combine())


if __name__ == '__main__':
    combine_readme()