from typing import List


def split_digits_by_four(num: str) -> List[str]:
    return [num[i:i+4] for i in range(0, len(num), 4)]


def read_four_digits(num: str) -> List[str]:
    """
    :param num: 阶序：个十百千
    """
    numToChinese = ["ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"]
    units = ["Shi", "Bai", "Qian"]
    result = []

    zero = False
    if num[0] == '0':
        zero = True
    else:
        result.insert(0, numToChinese[int(num[0])])

    for idx, one in enumerate(num[1:]):
        # 如果是连续0，将不做任何处理
        if not zero and one == '0':  # 如果上一个不是0，这一位是0，这时候需要把0读出来;
            # result = " " + "ling" + result
            result.insert(0, "ling")
            zero = True  # 状态变化
        elif one != '0':  # 只要不是0都要读出来，并且加上单位
            result.insert(0, units[idx])
            result.insert(0, numToChinese[int(one)])
            zero = False  # 状态变化

    return result


def summit():
    """
    倒过来读更加方便
    """
    units = ["", "Wan", "Yi"]
    string = input()
    sign = ""
    if string[0] == "-":
        num = string[1:]
        sign = "Fu"
    else:
        num = string

    result = []
    if int(num) == 0:
        print(" ".join([sign, 'ling']).strip())
        return 0

    for idx, group in enumerate(split_digits_by_four("".join(reversed(num)))):
        read = read_four_digits(group)
        if len(read) > 0:
            result = read_four_digits(group) + [units[idx]] + result
    result = [sign] + result
    print(" ".join(result).strip())


if __name__ == '__main__':
    summit()
