from functools import reduce


def summit():
    input()
    nums = list(map(int, input().split()))
    nums.sort()
    print(reduce(lambda a, b: int((a+b)/2), nums[1:], nums[0]))


if __name__ == '__main__':
    summit()
