import importlib
import os
import sys
import json
from io import StringIO
from utils.Exception import *
import logging


class Test:
    def __init__(self):
        with open("config.json", "r", encoding="utf-8") as f:
            self.config = json.load(f)
        self.testCases = None  # 测试用例的信息
        self.entry = None  # 模块的入口函数
        self.set_up()

    def set_up(self):
        # 如果未指定data.json的位置默认就是模块所在的位置
        dataPath = self.config["dataPath"] if self.config["dataPath"] is not None \
            else os.path.join(*self.config["module"].split(".")[:-1]+["data.json"])

        with open(dataPath, encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)

        # 如果指定了test case id，则只测试对应id的测试用例
        if self.config["testCaseId"] is not None:
            self.testCases = list(filter(lambda x: x["id"] == self.config["testCaseId"], self.testCases))

        # 如果设定了模块的入口函数
        if self.config["moduleEntry"] is not None:
            self.entry = self.config["moduleEntry"]
        else:
            self.entry = "summit"

    def run(self):
        module = importlib.import_module(self.config["module"])
        print(f"你正在测试的代码为：{self.config['module']}.py")
        for idx, testCase in enumerate(self.testCases):
            a, answer = testCase["data"], testCase["answer"]
            sys.stdin = StringIO(a)
            f = StringIO()
            stdoutBackup = sys.stdout
            sys.stdout = f
            getattr(module, self.entry)()
            assert answer == f.getvalue(), repr(
                f"error in id={testCase['id']},expected:{answer}, however:{f.getvalue()}")
            sys.stdout = stdoutBackup
            print(f"pass:id = {testCase['id']}")


if __name__ == '__main__':
    Test().run()
