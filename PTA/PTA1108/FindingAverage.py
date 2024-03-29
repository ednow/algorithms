from typing import List
import re


def summit():
    illegalNums: List[str] = []
    nums: List[float] = []
    numbers = input()
    pattern = re.compile(r"^[0]*((([-]?[1-9]\d{1,2})|[-]?\d)?([-]?\.\d{0,2})?|[-]?1000(\.[0]{0,2})?)$")
    if int(numbers) != 0:
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
        if nums[0] == 0:
            nums[0] = 0
        print(f"The average of 1 number is {nums[0]:.2f}")


if __name__ == '__main__':
    summit()
