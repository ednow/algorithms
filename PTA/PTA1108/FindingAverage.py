from typing import List
import re


def summit():
    illegalNums: List[str] = []
    nums: List[float] = []
    input()  # 不读取有几个数字
    pattern = re.compile(r"^[-]?(\d{1,3}(\.\d{1,2})?|1000)$")
    for num in input().split():
        if pattern.match(num) is not None:
            nums.append(float(num))
        else:
            illegalNums.append(num)

    for num in illegalNums:
        print(f"ERROR: {num} is not a legal number")

    numsLen = len(nums)
    if numsLen == 0:
        print("The average of 0 numbers is Undefined")
    elif numsLen > 1:
        print(f"The average of {numsLen} numbers is {sum(nums)/numsLen:.2f}")
    else:
        print(f"The average of 1 number is {nums[0]:.2f}")


if __name__ == '__main__':
    summit()
