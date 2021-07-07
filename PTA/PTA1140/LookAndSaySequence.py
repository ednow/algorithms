from typing import List
from collections import Counter
from functools import reduce


def say(num: str, step: int) -> str:
    if step == 0:
        return num
    count = Counter(num)
    result = reduce(lambda a, b: a + b + str(count[b]), num, "")
    step -= 1
    return say(result, step)


def summit():
    num, step = input().split()
    print(say(num, int(step)))


if __name__ == '__main__':
    summit()
