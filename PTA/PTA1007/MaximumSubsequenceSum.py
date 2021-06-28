from typing import List, Generator
from functools import reduce
import unittest


def next_positive_in_result(result: List[List[int]]) -> Generator:
    for i in range(len(result)):
        if sum(result[i]) > 0:
            yield i
    return -1


def split_positive_negative(nums: List[int]) -> List[List[int]]:
    result = []
    # 正负分割
    positive = False if nums[0] < 0 else True
    start = 0
    end = 0
    isChange = False
    for i in range(1, len(nums)):
        iPositive = False if nums[i] < 0 else True
        # 如果符号不相等
        if not(positive is iPositive):
            result.append(nums[start:i].copy())
            start = i
            positive = not positive
            isChange = True
    if start == len(nums) - 1:  # 考虑最后一位
        result.append(nums[-1:].copy())
    if not isChange:
        return [nums]

    return result


def merge_positive(result: List[List[int]]) -> None:
    # 试图合并正负序列
    isChange = False  # result列表有没有改变
    nextPositiveIdx = next_positive_in_result(result)
    while True:
        try:
            idx1 = next(nextPositiveIdx)
            idx2 = next(nextPositiveIdx)
            merge = reduce(lambda a, b: a + sum(b), result[idx1:idx2+1], 0)
            if sum(result[idx1]) < merge and sum(result[idx2]) < merge:
                result.insert(idx1, result[idx1] + result[idx2])
                del result[idx1+1:idx2+2]
                isChange = True
            if isChange:
                nextPositiveIdx = next_positive_in_result(result)
        except StopIteration:
            return None


def find_max_sequence(result: List[List[int]]) -> int:
    nextPositiveIdx = next_positive_in_result(result)
    maxIdx = next(nextPositiveIdx)
    while True:
        try:
            nextIdx = next(nextPositiveIdx)
            if sum(result[nextIdx]) > sum(result[maxIdx]):
                maxIdx = nextIdx
        except StopIteration:
            return maxIdx


def solution(nums: List[int]) -> str:
    result = split_positive_negative(nums)
    if len(result) == 1 and sum(result[0]) <= 0:  # 全是负数
        return f"0 {result[0][0]} {result[0][-1]}"
    merge_positive(result)
    idx = find_max_sequence(result)
    return f"{sum(result[idx])} {result[idx][0]} {result[idx][-1]}"


def summit():
    input()
    return solution(list(map(int, input().split())))


class TestPTA1007(unittest.TestCase):
    def setUp(self) -> None:
        import json
        with open("data.json", encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)

    # @unittest.skip
    def test_1007(self):
        # for idx, testCase in enumerate(self.testCases):  # test all
        for idx, testCase in enumerate([self.testCases[9]]):
            a, answer = testCase["data"], testCase["answer"]
            lines = a.split("\n")
            result = solution(list(map(int, lines[1].split())))
            assert answer == result, f"{answer}, {result}"

    @unittest.skip
    def test_next_positive_in_result(self):
        print(next(next_positive_in_result([[1], [2]])))


if __name__ == '__main__':
    print(summit())
