import re


# def find_first_not_zero(num: str):
#     search = re.search(r"[^0]", num)
#     if search is not None:  # 如果最后呈现000xxx
#         return search.start()


def summit():
    """

    """
    string = input()
    numSign = string[0]
    numSign = '' if numSign == '+' else numSign
    num, exp = string[1:].split("E")
    exp = int(exp)
    result = ""
    if exp == 0:
        result = numSign + num
    elif exp > 0:  # 小数点往右移动
        integer, fractional = num[0], num[2:]
        if len(fractional) < exp:  # 右移位数超过了小数部分的长度
            zeroToAdd = exp - len(fractional)  # 需要补0的个数
            result = numSign + integer + fractional + '0' * zeroToAdd
        elif len(fractional) == exp:  # 右移位数刚好等于小数部分的长度
            result = integer + fractional
            # 根据题意下面的情况不可能出现
            # if re.search(r"[^0]", result) is not None:  # 如果最后呈现000xxx
            #     result = result[re.search(r"[^0]", result).start():]  # 去掉前面的0使其变为xxx
            result = numSign + result
        else:  # 右移位数小于小数部分的长度
            floatPos = 1 + exp  # 小数点右移后的位置
            num = num.replace(".", "")
            integer, fractional = num[:floatPos+1], num[floatPos:]
            # 根据题意下面的情况不可能出现
            # if re.search(r"[^0]", integer) is not None:  # 如果整数部分呈现呈现000xxx
            #     integer = integer[re.search(r"[^0]", integer).start():]  # 去掉前面的0使其变为xxx
            # else:  # 整数部分全是0
            #     integer = '0'
            result = numSign + integer + "." + fractional
    elif exp < 0:
        zeroToAdd = - exp - 1
        # integer, fractional = num[0], num[2:]
        num = num.replace(".", "")
        result = numSign + '0' + '.' + '0' * zeroToAdd + num
    print(result)


if __name__ == '__main__':
    summit()
