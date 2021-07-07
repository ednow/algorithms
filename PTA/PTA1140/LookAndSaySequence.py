def say(num: str, step: int) -> str:
    if step == 1:
        return num
    now = 0
    duplicate = 0
    result = ""
    for idx, one in enumerate(num + "x"):
        if one != num[now]:
            result += f"{num[now]}{duplicate}"
            now = idx
            duplicate = 1
        else:
            duplicate += 1
    step -= 1
    return say(result, step)


def summit():
    num, step = input().split()
    print(say(num, int(step)))


if __name__ == '__main__':
    summit()
