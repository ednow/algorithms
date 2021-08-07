def summit():
    # 总共有多少条记录
    N = int(input())
    records = []
    result = ""
    for _ in range(N):
        strings = input().split()
        records.append(
            [strings[0], strings[1], int(strings[2])]
        )
    MIN, MAX = map(int, input().split())
    records = list(filter(lambda x: MIN <= x[2] <= MAX, records))
    if len(records) == 0:
        print("NONE")
        return None

    records.sort(key=lambda x: x[2], reverse=True)

    result += "\n".join([" ".join(i[:-1]) for i in records])

    print(result)


if __name__ == '__main__':
    summit()
