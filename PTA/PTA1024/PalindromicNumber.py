def check_is_num_palindromic(num: int) -> bool:
    numStr = str(num)
    numLen = len(numStr)
    for i in range(int(numLen/2)):
        if numStr[i] != numStr[numLen - i - 1]:
            return False
    return True


def reverse(num: int) -> int:
    return int("".join(reversed([i for i in str(num)])))


def find_pair(num: int, step: int):
    # 递归终止条件：是回文，或者步数用完
    if check_is_num_palindromic(num) or step == 0:
        return num, step
    step -= 1
    return find_pair(num + reverse(num), step)


def summit():
    string = input()
    num, step = map(int, string.split())
    num, remainStep = find_pair(num, step)
    print(f"{num}\n{step - remainStep}")


if __name__ == '__main__':
    summit()
