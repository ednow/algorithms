from typing import List, Dict


def summit():
    # 下表对应某个小时，值对应该小时的价格
    rates: List[int] = list(map(int, input().split()))
    recordsNum = int(input())

    # 每个人的账单
    bills = {}

    # 对于每一个人，存放其每一条记录
    records: Dict[str, List[List[str]]] = {}
    for _ in range(recordsNum):
        record = input().split()
        records.get(record[0]).append(record[1:])


if __name__ == '__main__':
    summit()
