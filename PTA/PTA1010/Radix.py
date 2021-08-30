from typing import Tuple


def num_to_decimal(num: str, radix: int) -> int:
    """
    将任意进制数转为10进制
    :param num:
    :param radix: 底
    """
    symbol_to_decimal = "0123456789abcdefghijklmnopqrstuvwxyz"
    result = 0
    for idx, i in enumerate(reversed(num)):
        result += symbol_to_decimal.index(i) * radix ** idx
    return result


def is_num_equal(num_radix_known: str, num_radix_unknown: str, radix: int) -> Tuple[bool, int]:
    """

    :param num_radix_known:
    :param num_radix_unknown:
    :param radix: num_radix_known的进制
    :return:
    """
    symbol_to_decimal = "0123456789abcdefghijklmnopqrstuvwxyz"
    is_equal = False
    num = num_to_decimal(num_radix_known, radix)
    radix_range = []

    if len(num_radix_unknown) > len(num_radix_known):
        radix_range = range(radix)

    if len(num_radix_unknown) == len(num_radix_known):
        radix_range = [radix]

    if len(num_radix_unknown) < len(num_radix_known):
        max_radix = radix+1
        highest = symbol_to_decimal.index(num_radix_unknown[0])
        power = (len(num_radix_unknown) - 1)
        while highest * max_radix ** power < num:
            max_radix += 1
        radix_range = range(radix+1, max_radix)

    radix = 0

    for i in radix_range:
        # 数的真值和已知进制的数的真值相等
        if num == num_to_decimal(num_radix_unknown, i):
            is_equal = True
            radix = i
            break
    # 测试点19
    if max(symbol_to_decimal.index(i)+1 for i in num_radix_unknown) > radix:
        is_equal = False
    return is_equal, radix


def summit():
    num1, num2, tag, radix = input().split()
    if int(tag) == 1:
        is_equal, radix = is_num_equal(num1, num2, int(radix))
    else:
        is_equal, radix = is_num_equal(num2, num1, int(radix))

    if is_equal:
        print(radix, end="")
    else:
        print("Impossible", end="")


if __name__ == '__main__':
    summit()
