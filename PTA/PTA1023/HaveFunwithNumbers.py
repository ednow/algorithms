import unittest


def summit(string):
    result = ""
    rawNums = set(string)
    doubledResult = 2 * int(string)
    doubledNums = set(str(doubledResult))
    intersectionLen = len(rawNums) - len(doubledNums)
    return f"{'Yes' if intersectionLen == 0 else 'No'}\n{doubledResult}"


class TestPTA1023(unittest.TestCase):
    def setUp(self) -> None:
        import json
        with open("data.json", encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)

    def test_pta1023(self):
        for idx, testCase in enumerate(self.testCases):
            a, answer = testCase["data"], testCase["answer"]
            result = summit(a)
            assert answer == result, f"{answer}, {result}"


if __name__ == '__main__':
    print(summit(input()), end="")