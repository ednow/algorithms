def summit():
    input()
    nums = list(map(int, input().split()))
    nums.sort()
    print(min(nums[-1] - 1, int((nums[-1] + nums[-2])/2)))


if __name__ == '__main__':
    summit()
