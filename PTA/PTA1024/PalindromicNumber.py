import unittest


def check_is_num_palindromic(num: int) -> bool:
    numStr = str(num)
    numLen = len(numStr)
    for i in range(int(numLen/2)):
        if numStr[i] != numStr[numLen - i - 1]:
            return False
    return True


def reverse(num: int) -> int:
    return int("".join(reversed([i for i in str(num)])))


def find_pair(num: int, step: int):
    # 递归终止条件：是回文，或者步数用完
    if check_is_num_palindromic(num) or step == 0:
        return num, step
    step -= 1
    return find_pair(num + reverse(num), step)


def summit(string) -> str:
    num, step = map(int, string.split())
    num, remainStep = find_pair(num, step)
    return f"{num}\n{step - remainStep}"


class TestPTA1024(unittest.TestCase):
    def setUp(self) -> None:
        import json
        with open("data.json", encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)
        with open("config.json", encoding="utf-8", mode="r") as f:
            self.config = json.load(f)

        if any(list(self.config.values())):
            self.testCases = list(filter(lambda x: x["id"] == self.config["testCaseId"], self.testCases))

    def test_pta1024(self):
        for idx, testCase in enumerate(self.testCases):
            a, answer = testCase["data"], testCase["answer"]
            result = summit(a)
            assert answer == result, f"{answer}, {result}"


if __name__ == '__main__':
    print(summit(input()))