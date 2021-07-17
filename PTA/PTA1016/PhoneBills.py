from typing import List, Dict


def summit():
    # 下表对应某个小时，值对应该小时的价格
    rates: List[int] = list(map(int, input().split()))
    recordsNum = int(input())
    result = ""
    # 对于每一个人，存放其每一条记录
    # (一条记录是一个List，[[时间], 状态])
    records: Dict[str, List[List]] = {}
    for _ in range(recordsNum):
        record = input().split()
        before = records.get(record[0],[])
        before.append([list(map(int, record[1].split(":"))), record[2]])
        records[record[0]] = before

    # 每个人的账单
    bills = {}
    # 对于每一个人，排序并求其账单
    for one in records.keys():
        # 按照日排序，题目明说了一个测试用例，只有一个月
        records[one].sort(
            key=lambda x: x[0][1]
        )

        onLine = -1
        # 找到第一条onLine的记录
        # off-line
        # on-line
        for idx in range(len(records[one])):
            if records[one] == 'on-line':
                onLine = idx

        if onLine == -1:  # 全是off-line，不合法的记录
            continue
        else:
            for idx in range(onLine, len(records[one])):
                if records[one] == 'on-line':  # 上一天on-line没有pair off-line
                    onLine = idx
                else:  # 计算账单
                    bill = 0  # 账单
                    last = 0  # 持续时间
                    oneDetail = bills.get(one, {})  # 某个人的账单列表，总的账单
                    oneBill = oneDetail.get("bills", [])  # 账单列表
                    oneTotal = oneDetail.get("total", 0)  # 总的账单

                    # 如果在同一天
                    if records[one][onLine][0][1] == records[one][idx][0][1]:
                        if records[one][onLine][0][2] == records[one][idx][0][2]:  # 如果在同一个小时
                            last += records[one][idx][0][3] - records[one][onLine][0][3]
                            bill += last * rates[records[one][idx][0][2]] / 100
                        else:  # 不在同一个小时
                            # 先求出on-line的小时，到该小时结束花的钱
                            temp = 60 - records[one][onLine][0][3]
                            bill += temp * rates[records[one][onLine][0][2]]
                            last += temp
                            # 再求出off-line的时候，花的钱
                            bill += records[one][idx][0][3] * rates[records[one][idx][0][2]]
                            last += records[one][idx][0][3]
                            # 求出中间小时花的钱
                            for hour in range(records[one][onLine][0][2] + 1, records[one][idx][0][2]):
                                bill += 60 * rates[hour]
                                last += 60
                    else:  # 不在同一天
                        # 把on-line 那一天的钱结了
                        # 计算on-line 那个小时的钱
                        temp = 60 - records[one][onLine][0][3]
                        bill += temp * rates[records[one][onLine][0][2]]
                        last += temp
                        # 结算那一天剩下的小时
                        for hour in range(records[one][onLine][0][2] + 1, 24):
                            last += 60
                            bill += 60 * rates[hour]
                        # 把off-line 那一天的钱结了
                        last += records[one][idx][0][3]
                        bill += records[one][idx][0][3] * rates[records[one][idx][0][2]]
                        for hour in range(0, records[one][idx][0][2]):
                            last += 60
                            bill += 60 * rates[hour]
                        # 把中间天的钱结了
                        for _ in range(records[one][onLine][0][1], records[one][idx][0][1]):
                            last += 24 * 60
                            bill += sum(rates) * 60

                    bills[one]["bills"] = oneBill.append(
                        [
                            ":".join([f"{i:02d}" for i in records[one][onLine]]) + ' ' +
                            ":".join([f"{i:02d}" for i in records[one][idx]]) + ' ' +
                            str(last) +
                            '$' + f"{bill:.2f}"
                        ]
                    )
                    bills[one]["total"] = oneTotal + bill

    # 得到账单的月份
    month = 0
    for bill in bills.values():
        month = bill[0][0]

    # 对账单进行字母表排序
    bills = sorted(bills.items(), key=lambda x:x[0])
    for one, oneBills in bills:
        result += one + ' ' + f"{month:02d}" + \
                "\n".join(oneBills["bills"]) + "\n" + \
                oneBills["total"] + "\n"

    print(result)


if __name__ == '__main__':
    summit()
