from typing import List


def extract_details(name: str, signIn: str, signOut: str):
    return {
        "name": name,
        "signIn": sum([60 ** (2 - idx) * int(i) for idx, i in enumerate(signIn.split(":"))]),
        "signOut": sum([60 ** (2 - idx) * int(i) for idx, i in enumerate(signOut.split(":"))]),
    }


def solution(memberInfos: List):
    unlock = f"{sorted(memberInfos, key=lambda x: x['signIn'])[0]['name']}"
    lock = f"{sorted(memberInfos, key=lambda x: x['signOut'])[-1]['name']}"

    return f"{unlock} {lock}"


def summit():
    memberInfos = []
    members = int(input())
    while members > 0:
        string = input()
        memberInfos.append(
            extract_details(*(string.split()))
        )
        members -= 1
    print(solution(memberInfos), end="")


if __name__ == '__main__':
    summit()
