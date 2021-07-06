import unittest
import sys
from io import StringIO


def summit():
    """

    """
    string = input()
    numSign = string[0]
    num, exp = string[1:].split("E")
    exp = int(exp)

    if exp == 0:
        print(numSign + num)
    elif exp > 0:
        pass
    elif exp < 0:
        pass

class TestPTA1061(unittest.TestCase):
    def setUp(self) -> None:
        import json
        with open("data.json", encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)

        with open("config.json", encoding="utf-8", mode="r") as f:
            self.config = json.load(f)

        if any(list(self.config.values())):
            self.testCases = list(filter(lambda x: x["id"] == self.config["testCaseId"], self.testCases))

    def test_pta1061(self):
        for idx, testCase in enumerate(self.testCases):
            a, answer = testCase["data"], testCase["answer"]
            sys.stdin = StringIO(a)
            f = StringIO()
            sys.stdout = f
            summit()
            assert answer == f.getvalue(), f"{testCase['id']}right:{answer}, my:{f.getvalue()}"


if __name__ == '__main__':
    summit()