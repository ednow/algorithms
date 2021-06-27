from typing import List
import unittest


def summit(string):
    numToEn = {
        1: "one",
        2: "two",
        3: "three",
        4: "four",
        5: "five",
        6: "six",
        7: "seven",
        8: "eight",
        9: "nine",
    }
    nums: List[int] = [int(i) for i in string]
    return " ".join([numToEn[int(i)] for i in str(sum(nums))])


class TestPTA1005(unittest.TestCase):
    def test_1005(self):
        testCases = [
            ["one five", "12345"],  # 案例
        ]

        for answer, a in testCases:
            result = summit(a)
            assert answer == result, f"{answer}, {result}"


if __name__ == '__main__':
    print(summit(input()), end="")
