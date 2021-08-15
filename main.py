import importlib
import os
import sys
import json
import traceback
from io import StringIO
from utils.Exception import *
import logging


class Test:
    def __init__(self):
        with open("config.json", "r", encoding="utf-8") as f:
            self.config = json.load(f)
        self.testCases = []  # 测试用例的信息
        self.entry = None  # 模块的入口函数
        self.set_up()

    def set_up(self):
        # 如果未指定data.json的位置默认就是模块所在的位置
        dataPath = self.config["dataPath"] if self.config["dataPath"] is not None \
            else os.path.join(*self.config["module"].split(".")[:-1]+["data.json"])

        with open(dataPath, encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)

        # 如果指定了test case id 或者测试数据，则只测试对应的测试用例
        temp = []
        mapper = {
            "testCaseId": "id",
            "testData": "data"
        }

        # 给定testCaseId中的测试数据，只添加给定的测试数据
        for key in ["testCaseId", "testData"]:
            if self.config.get(key, None) is not None:
                temp.extend(list(filter(lambda x: x[mapper[key]] == self.config[key], self.testCases)))
        if len(temp) > 0:
            self.testCases = temp

        # 删除excludeTestCaseIds中指定的测试数据
        if self.config.get("excludeTestCaseIds", None) is not None:
            if len(self.config.get("excludeTestCaseIds")) > 0:
                self.testCases = list(
                    filter(
                        lambda x: not(x["id"] in self.config["excludeTestCaseIds"]),
                        self.testCases
                    )
                )

        # 如果设定了模块的入口函数
        if self.config.get("moduleEntry", None) is not None:
            self.entry = self.config["moduleEntry"]
        else:
            self.entry = "summit"

        # 是否接管stdout
        if self.config.get("isTakeOverOutput", None) is not None:
            if not isinstance(self.config["isTakeOverOutput"], bool):
                assert False, f"'isTakeOverOutput' should be boolean,not {type(self.config['isTakeOverOutput'])}"
            setattr(self, "isTakeOverOutput", self.config["isTakeOverOutput"])
        else:
            setattr(self, "isTakeOverOutput", True)

    def run(self):
        module = importlib.import_module(self.config["module"])
        print(f"你正在测试的代码为：{self.config['module']}.py")
        for idx, testCase in enumerate(self.testCases):
            a, answer = testCase["data"], testCase["answer"]
            sys.stdin = StringIO(a)
            f = StringIO()
            stdoutBackup = sys.stdout
            if getattr(self, 'isTakeOverOutput'):
                sys.stdout = f
            try:
                getattr(module, self.entry)()
            except Exception as e:
                print(traceback.format_exc(), file=sys.stderr)
                sys.stdout = stdoutBackup
                print(f.getvalue())
                continue

            sys.stdout = stdoutBackup
            if answer == f.getvalue():
                print(f"pass:id = {testCase['id']}")
            else:
                errors = [
                    f"error id   : {testCase['id']}",
                    f"data       : {testCase['data']}",
                    f"got        : {f.getvalue()}",
                    f"expected   : {answer}",
                    f"description: {testCase['description']}",

                ]
                for error in errors:
                    print(repr(error), file=sys.stderr)
                print("-" * 10, file=sys.stderr)


if __name__ == '__main__':
    Test().run()
