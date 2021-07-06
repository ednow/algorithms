from typing import List
from functools import reduce


def next_positive_in_result(result: List[List[int]], now: int) -> int:
    """
    :param result:
    :param now: 现在指针的位置
    :return:
    """
    for i in range(now+1, len(result)):
        if sum(result[i]) >= 0:
            return i
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
    # if start == len(nums) - 1:  # 考虑最后一位
    result.append(nums[start:].copy())  # 帮前面的循环收尾
    if not isChange:  # 符号都一样
        return [nums]

    return result


def delete_zero_at_last(l: List[int]) -> None:
    if sum(l) == 0:  # 只有0不考虑
        return None
    while l[-1] == 0:
        del l[-1]


def merge_positive(result: List[List[int]]) -> None:
    # 试图合并正负序列
    isChange = False  # result列表有没有改变
    now = 0 if sum(result[0]) > 0 else next_positive_in_result(result, 0)
    while now != -1:
        nextPositiveIdx = next_positive_in_result(result, now)
        if nextPositiveIdx == -1:
            break
        merge = reduce(lambda a, b: a + sum(b), result[now:nextPositiveIdx+1], 0)
        if sum(result[now]) < merge and sum(result[nextPositiveIdx]) <= merge:  # 保证i最小
            result.insert(now, reduce(lambda a, b: a + b, result[now:nextPositiveIdx+1], []))
            del result[now+1:nextPositiveIdx+2]
            isChange = True
        else:
            isChange = False
            now = nextPositiveIdx
            nextPositiveIdx = next_positive_in_result(result, now)
        if isChange:
            now = nextPositiveIdx
            nextPositiveIdx = next_positive_in_result(result, now)


def find_max_sequence(result: List[List[int]]) -> int:
    maxIdx = 0
    for i in range(len(result)):
        if sum(result[i]) > sum(result[maxIdx]):
            maxIdx = i
    return maxIdx


def solution(nums: List[int]) -> str:
    """
    :param nums:
    :return: "maxSum maxSequenceFirstItem maxSequenceLastItem"
    """
    result = split_positive_negative(nums)
    if len(result) == 1 and sum(result[0]) <= 0:  # 全是负数
        return f"0 {result[0][0]} {result[0][-1]}"
    merge_positive(result)
    idx = find_max_sequence(result)
    # fix: id="24-2"
    delete_zero_at_last(result[idx])
    return f"{sum(result[idx])} {result[idx][0]} {result[idx][-1]}"


def summit():
    input()
    print(solution(list(map(int, input().split()))))


if __name__ == '__main__':
    summit()
