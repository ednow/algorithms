from typing import List


def summit():
    string = input()
    numToEn = {
        0: "zero",
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
    print(" ".join([numToEn[int(i)] for i in str(sum(nums))]), end="")


if __name__ == '__main__':
    summit()
