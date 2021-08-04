def summit():
    # N一共有多少人.K请求的个数
    N, K = map(int, input().split())
    # 每一条记录由一个list维护,[姓名, 年龄, 净盈利]
    records = []
    # 每一条请求由一个list维护[前n项, 最小年龄, 最大年龄]
    queries = []
    # 最后输出的字符串
    result = ""

    # 读入记录
    for _ in range(N):
        strings = input().split()
        # print(strings)
        records.append([strings[0], int(strings[1]), int(strings[2])])

    # 读入请求
    for _ in range(K):
        queries.append(list(map(int, input().split())))

    for idx, query in enumerate(queries):
        raw = list(filter(lambda x: query[1] <= x[1] <= query[2], records))
        # 三个关键字的先后顺序的原理详见数据结构习题
        # 先根据年龄和姓名非降序排序
        raw.sort(key=lambda x: (x[1], x[0]))
        # 再根据净利润降序排序
        raw.sort(key=lambda x: x[2], reverse=True)
        result += f'Case #{idx + 1}:\n'
        if len(raw) != 0:  # 如果存在记录
            for _idx in range(min(len(raw), query[0])):
                result += " ".join(map(str, raw[_idx])) + '\n'
        else:
            result += 'None\n'

    print(result.rstrip(), end='')


if __name__ == '__main__':
    summit()
