def check_is_num_palindromic(numStr: str) -> bool:
    numLen = len(numStr)
    for i in range(int(numLen/2)):
        if numStr[i] != numStr[numLen - i - 1]:
            return False
    return True


def reverse(numStr: str) -> str:
    return "".join(reversed([i for i in numStr]))


def summit():
    string = input()
    num, step = string.split()
    remainStep = step = int(step)
    carry = 0
    while remainStep > 0 and not check_is_num_palindromic(num):
        numReverse = reverse(num)
        result = ""
        numLen = len(numReverse)
        for i in range(numLen):
            acc = str(int(numReverse[numLen - i - 1]) + int(num[numLen - i - 1]) + carry)
            result = acc[-1] + result
            carry = 1 if len(acc) > 1 else 0
        if carry == 1:
            result = "1" + result
        num = result
        carry = 0
        remainStep -= 1
    return f"{num}\n{step - remainStep}"


if __name__ == '__main__':
    summit()