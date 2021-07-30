def summit():
    N, C = map(int, input().split())
    records = []
    for _ in range(N):
        strings = input().split()
        records.append([strings[0], strings[1], strings[2]])

    if C == 1:
        records.sort(key=lambda x: int(x[0]))
    elif C == 2:
        records.sort(key=lambda x: (x[1], int(x[0])))
    elif C == 3:
        records.sort(key=lambda x: (int(x[2]), int(x[0])))

    resultStr = ""
    for idx in range(len(records)):
        resultStr += " ".join(records[idx]) + "\n"

    print(resultStr, end="")


if __name__ == '__main__':
    summit()
