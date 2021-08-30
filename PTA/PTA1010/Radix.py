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
        # 测试点0：symbol不应该大于radix
        if symbol_to_decimal.index(i) >= radix:
            return -1
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

    min_radix = 0
    max_radix = num+1  # 记得+1测试点0
    while min_radix <= max_radix:
        mid_radix = int((min_radix + max_radix)/2)
        mid_num = num_to_decimal(num_radix_unknown, mid_radix)
        if mid_num == num:
            is_equal = True
            radix = mid_radix
            break

        if mid_num > num:
            max_radix = mid_radix - 1

        if mid_num < num:
            min_radix = mid_radix + 1

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
