from typing import List,Dict
import unittest


def extract_details(name: str, signIn: str, signOut: str):
    return {
        "name": name,
        "signIn": sum([60**(2-idx) * int(i) for idx, i in enumerate(signIn.split(":"))]),
        "signOut": sum([60 ** (2 - idx) * int(i) for idx, i in enumerate(signIn.split(":"))]),
    }


def solution(memberInfos: List):
    unlock = f"{sorted(memberInfos, key=lambda x: x['signIn'])[0]['name']}"
    lock = f"{sorted(memberInfos, key=lambda x: x['signOut'])[-1]['name']}"

    return f"{unlock} {lock}"


def summit():
    memberInfos = []
    members = int(input())
    while members > 0:
        memberInfos.append(
            {
                extract_details(*input().split())
            }
        )
        members -= 1
    return solution(memberInfos)


class TestPTA1006(unittest.TestCase):
    def setUp(self) -> None:
        import json
        with open("data.json", encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)

    def test_1006(self):
        for testCase in self.testCases:
            a, answer = list(testCase.values())
            memberInfos = [extract_details(*i.split()) for i in a.split("\n")[1:]]
            result = solution(memberInfos)
            assert answer == result, f"{answer}, {result}"


if __name__ == '__main__':
    print(summit(), end="")
