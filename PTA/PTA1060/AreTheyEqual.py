import unittest
import sys
from io import StringIO
from typing import Tuple
import re
# def delete_zero_at_tail(num: str):
#     pass


def separate_digits_power(num: str, significant: int) -> Tuple[str, str]:
    """
    :param num: 数字的字符串
    :param significant: 保留的位数
    :return: 有效位数， 幂
    """
    result = ""
    floatPos = str(num.find("."))
    notFloat = False  # 有没有小数点
    if re.search(r'[^0]', num[:num.find(".")]) is None and num[0] == '0':  # id=12,如果这个数字前面有多余的0
        if num.find(".") == -1:  # 是小数还是整数
            num = num[num.find("."):]  # 将000xxx转化位xxx
        else:
            num = "0" + num[num.find("."):]  # 将000.xxx转换为0.xxx
        floatPos = str(num.find("."))

    if float(num) == 0:  # 如果这个数字是0，幂次是0
        return '0' * significant, '0'

    if floatPos == '-1':  # 没有小数点
        notFloat = True

    num = num.replace(".", "")
    if floatPos == '1' and num[0] == "0":  # id=6，如果是0.xxx，
        num = num[1:]  # 切片掉前面的0
        if num[0] == "0":  # id=11，如果是0.0..0xxx，
            notZeroPos = re.search(r'[^0]', num).start()
            floatPos = f'-{notZeroPos}'
            num = num[notZeroPos:]
        else:
            floatPos = '0'

    numLen = len(num)
    if numLen >= significant:
        result += num[:significant]
    else:
        result += num + "0" * (significant - numLen)

    if notFloat:  # 如果没有小数点，幂次是字符串的长度
        floatPos = str(numLen)

    return result, floatPos


def summit():
    digits = input().split()
    significant, digits = int(digits[0]), digits[1:]
    choppedDigitsList = [separate_digits_power(i, significant) for i in digits]
    choppedDigits = set(choppedDigitsList)
    if len(choppedDigits) == 1:
        print(f"YES 0.{list(choppedDigits)[0][0]}*10^{list(choppedDigits)[0][1]}")
    else:
        print(f"NO {' '.join(['0.' + i[0] + '*10^' + str(i[1]) for i in choppedDigitsList])}")


class TestPTA1060(unittest.TestCase):
    def setUp(self) -> None:
        import json
        with open("data.json", encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)

        with open("config.json", encoding="utf-8", mode="r") as f:
            self.config = json.load(f)

        if any(list(self.config.values())):
            self.testCases = list(filter(lambda x: x["id"] == self.config["testCaseId"], self.testCases))

    def test_pta101060(self):
        for idx, testCase in enumerate(self.testCases):
            a, answer = testCase["data"], testCase["answer"]
            sys.stdin = StringIO(a)
            f = StringIO()
            sys.stdout = f
            summit()
            assert answer == f.getvalue(), f"{testCase['id']}right:{answer}, my:{f.getvalue()}"


if __name__ == '__main__':
    summit()