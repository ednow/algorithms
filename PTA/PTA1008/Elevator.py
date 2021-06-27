from typing import List, Dict
import unittest
from functools import reduce


def summit(string):
    return reduce(
        lambda a, b: 5 + a + (b - a) * 6 if b > a else (a - b) * 4,
        map(int, string.split()),
        0
    )


class TestPTA1008(unittest.TestCase):
    def setUp(self) -> None:
        import json
        with open("data.json", encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)

    def test_pta1008(self):
        for idx, testCase in enumerate(self.testCases):
            a, answer = list(testCase.values())
            result = summit(a)
            assert answer == result, f"{answer}, {result}"


if __name__ == '__main__':
    print(summit(input()), end="")
