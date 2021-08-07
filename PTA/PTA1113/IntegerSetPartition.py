def summit():
    input()
    nums = list(map(int, input().split()))
    nums.sort()
    print(f"{len(nums) % 2} {sum(nums[int(len(nums)/2):]) - sum(nums[:int(len(nums)/2)])}")


if __name__ == '__main__':
    summit()
