from math import sqrt


def is_prime(num: int) -> bool:
    for i in range(2, int(sqrt(num))):
        if num % i == 0:
            return False
    return True


def summit():
    numLen, primeLen = map(int, input().split())
    num = input()
    find = False
    result = ""
    for i in range(numLen - primeLen + 1):
        result = num[i: i + primeLen]
        if is_prime(int(result)):
            find = True
            break

    if find:
        print(result)
    else:
        print("404")


if __name__ == '__main__':
    summit()
