import unittest


def summit(string):
    result = 0
    q = list(map(int, string.split()))
    for now, destination in zip(([0]+q)[:-1], q):
        if now > destination:
            result += (now - destination) * 4
        else:
            result += (destination - now) * 6
        result += 5
    return f"{result}"


class TestPTA1008(unittest.TestCase):
    def setUp(self) -> None:
        import json
        with open("data.json", encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)

    def test_pta1008(self):
        for idx, testCase in enumerate(self.testCases):
            a, answer = list(testCase.values())
            result = summit(a)
            assert answer == result, f"{answer}, {result}"


if __name__ == '__main__':
    print(summit(input()), end="")
