def summit():
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
            result = numSign + result
        else:  # 右移位数小于小数部分的长度
            floatPos = 1 + exp  # 小数点右移后的位置
            num = num.replace(".", "")
            integer, fractional = num[:floatPos], num[floatPos:]
            result = numSign + integer + "." + fractional
    elif exp < 0:
        zeroToAdd = - exp - 1
        num = num.replace(".", "")
        result = numSign + '0' + '.' + '0' * zeroToAdd + num
    print(result)


if __name__ == '__main__':
    summit()
