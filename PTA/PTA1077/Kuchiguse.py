def summit():
    linesNum = int(input())
    lines = []
    maxCommonIdx = -1
    while linesNum > 0:
        lines.append(list(reversed(list(input().strip()))))
        linesNum -= 1
    for idx, characters in enumerate(zip(*lines)):
        if len(set(characters)) > 1:
            break
        maxCommonIdx += 1

    if maxCommonIdx == -1:
        print("nai")
    else:
        print("".join(reversed(lines[0][:maxCommonIdx + 1])))


if __name__ == '__main__':
    summit()
