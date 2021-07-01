import unittest


def check_is_num_palindromic(numStr: str) -> bool:
    numLen = len(numStr)
    for i in range(int(numLen/2)):
        if numStr[i] != numStr[numLen-1]:
            return False
    return True


def reverse(numStr: str) -> str:
    return "".join(reversed([i for i in numStr]))


def summit(string) -> str:
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


class TestPTA1024_2(unittest.TestCase):
    def setUp(self) -> None:
        import json
        with open("data.json", encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)
        with open("config.json", encoding="utf-8", mode="r") as f:
            self.config = json.load(f)

        if any(list(self.config.values())):
            self.testCases = list(filter(lambda x: x["id"] == self.config["testCaseId"], self.testCases))

    def test_pta1024_2(self):
        for idx, testCase in enumerate(self.testCases):
            a, answer = testCase["data"], testCase["answer"]
            result = summit(a)
            assert answer == result, f"id={testCase['id']}\n{answer},\n{result}"
            print(testCase['id'])


if __name__ == '__main__':
    print(summit(input()))