from typing import List, Dict
import unittest


def solution(nums: List[int]) -> str:
    result = []
    # 正负分割
    negative = False
    for i in range(len(nums)):
        pass

    # 试图合并正负序列
    # while
    return ""


def summit():
    input()
    return solution(list(map(int, input().split())))


class TestPTA1006(unittest.TestCase):
    def setUp(self) -> None:
        import json
        with open("data.json", encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)

    def test_1006(self):
        for idx, testCase in enumerate(self.testCases):
            a, answer = list(testCase.values())
            # memberInfos = [extract_details(*i.split()) for i in a.split("\n")[1:]]
            result = ""
            assert answer == result, f"{answer}, {result}"


if __name__ == '__main__':
    print(summit(), end="")
