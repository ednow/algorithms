from typing import List


def summit():
    # result
    resultString = ""
    # 结果由一个List来组织[注册号, 全局排名, 区域编码, 区域排名]
    result: List[List[int]] = []
    # 考生的信息由一个List来组织[注册号, 成绩, 区域编码]
    records: List[List[int]] = []

    # 读取数据
    locationNum = int(input())
    for location in range(1, locationNum+1):
        for _ in range(int(input())):
            strings = input().split()
            records.append(
                [strings[0], int(strings[1]), location]
            )

    # 初始化每个区域的最后面排名的序号
    localRank = {
        i: {
          "rank": 0,  # 现在的排名
          "score": -1,  # 现在排名的成绩
          "idx": 0,  # 已经找到的这个区域的人的数量
        } for i in range(1, locationNum+1)
    }

    records.sort(key=lambda x: x[1], reverse=True)
    rank = 0
    score = -1

    for idx in range(len(records)):
        if records[idx][1] != score:  # 如果全排名成绩不同,排名更新
            rank = idx + 1
            score = records[idx][1]

        localRank[records[idx][2]]["idx"] += 1

        if records[idx][1] != localRank[records[idx][2]]["score"]:  # 跟现在的区域成绩不一样，说明此人排名更后
            localRank[records[idx][2]]["rank"] = localRank[records[idx][2]]["idx"]
            localRank[records[idx][2]]["score"] = records[idx][1]

        result.append(
            [records[idx][0], rank, records[idx][2], localRank[records[idx][2]]["rank"]]
        )

    # 测试点1，按照注册号排序
    result.sort(key=lambda x: (x[1], x[0]))

    resultString += str(len(records)) + "\n"
    for record in result:
        resultString += " ".join(map(str, record)) + "\n"

    print(resultString.rstrip(), end="")


if __name__ == '__main__':
    summit()
