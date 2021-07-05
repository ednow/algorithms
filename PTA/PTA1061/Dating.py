import unittest
import sys
from io import StringIO


def summit():
    """
    假设地x个相同大写字母,出现在字符串的同一个位置
    """
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    alphabet = alphabet.lower() + alphabet
    weekBet = "ABCDEFG"
    hourBet = "0123456789ABCDEFGHIJKLMN"
    weekDay = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
    string1 = input().strip()
    string2 = input().strip()
    string3 = input().strip()
    string4 = input().strip()
    maxLen1 = min(len(string1), len(string2))
    maxLen2 = min(len(string3), len(string4))
    week = ''
    hours = 0
    minutes = 0

    isSelectWeek = True  # 是否是挑选星期
    for a, b in zip(string1[:maxLen1], string2[:maxLen1]):
        if a == b:
            if isSelectWeek and a in weekBet:
                week = weekDay[weekBet.find(a)]
                isSelectWeek = False
            elif not isSelectWeek and a in hourBet:
                hours = hourBet.find(a)
                break

    for idx, (a, b) in enumerate(zip(string3[:maxLen2], string4[:maxLen2])):
        if a == b:
            if a in alphabet:
                minutes = idx
    print(f"{week} {hours:>02d}:{minutes:>02d}")


class TestPTA1061(unittest.TestCase):
    def setUp(self) -> None:
        import json
        with open("data.json", encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)

        with open("config.json", encoding="utf-8", mode="r") as f:
            self.config = json.load(f)

        if any(list(self.config.values())):
            self.testCases = list(filter(lambda x: x["id"] == self.config["testCaseId"], self.testCases))

    def test_pta1061(self):
        for idx, testCase in enumerate(self.testCases):
            a, answer = testCase["data"], testCase["answer"]
            sys.stdin = StringIO(a)
            f = StringIO()
            sys.stdout = f
            summit()
            assert answer == f.getvalue(), f"{testCase['id']}right:{answer}, my:{f.getvalue()}"


if __name__ == '__main__':
    summit()