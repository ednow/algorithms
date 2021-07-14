from typing import Dict, List


def summit():
    studentsNum, checkNum = map(int, input().split())
    students: Dict[str, List[int]] = {}
    result = ""

    # 读入
    for _ in range(studentsNum):
        infos = input().split()
        students[infos[0]] = list(map(int, infos[1:]))
        students[infos[0]].insert(0, int(sum(students[infos[0]])/3))

    studentsItem = students.items()

    # 对每门学科各自排序
    rankA = list(dict(sorted(studentsItem, key=lambda x: x[1][0], reverse=True)).keys())
    rankC = list(dict(sorted(studentsItem, key=lambda x: x[1][1], reverse=True)).keys())
    rankM = list(dict(sorted(studentsItem, key=lambda x: x[1][2], reverse=True)).keys())
    rankE = list(dict(sorted(studentsItem, key=lambda x: x[1][3], reverse=True)).keys())

    # 对每一个请求输出最高排名, 排序优先级ACME
    ranks = [rankA, rankC, rankM, rankE]

    # 修正排名
    # _ranks = [{}] * 4:这样子每个的{}的索引都相同
    _ranks = [{}, {}, {}, {}]
    for rankId, rank in enumerate(ranks):
        _ranks[rankId][rank[0]] = 1  # 让第一个排名第一
        compare = students[rank[0]][rankId]  # 获得第一个成绩
        rightRank = 1  # 真正的排名是1
        for idx in rank[1:]:
            if compare == students[idx][rankId]:
                _ranks[rankId][idx] = rightRank  # 和上一个的排名相同
            else:
                rightRank += 1
                _ranks[rankId][idx] = rightRank

    ranks = _ranks

    mapper = {
        0: 'A',
        1: 'C',
        2: 'M',
        3: 'E'
    }
    for _ in range(checkNum):
        request = input()
        try:
            minIdx = min(enumerate(ranks), key=lambda x: x[1][request])[0]
            result += f"{ranks[minIdx][request]} {mapper[minIdx]}\n"
        except KeyError:  # 没有这号学生
            result += f"N/A\n"

    print(result, end='')


if __name__ == '__main__':
    summit()
