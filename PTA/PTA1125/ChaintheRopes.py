from typing import List


def fold(currentLen: int, ropes: List[int]) -> int:
    """
    将绳子对折
    :param currentLen: 现在对折的长度
    :param ropes: 还没折的绳子
    """
    # 没有绳子了，退出递归
    if len(ropes) == 0:
        return currentLen

    # nextLen = int((currentLen + ropes[0])/2)
    nextLen = int(currentLen / 2) + int(ropes[0] / 2)
    if nextLen > currentLen:
        fold(nextLen, ropes[1:])
    else:  # 现在的长度已经是最大了，退出递归
        return currentLen


def summit():
    input()
    nums = list(map(int, input().split()))
    nums.sort(reverse=True)
    print(fold(int(nums[1]/2)+int(nums[0]/2), nums[2:]))


if __name__ == '__main__':
    summit()
