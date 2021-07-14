from typing import Dict, List


def summit():
    studentsNum, checkNum = map(int, input().split())
    students: Dict[str, List[int]] = {}

    # 读入
    for _ in range(studentsNum):
        infos = input().split()
        students[infos[0]] = list(map(int, infos[1:]))
        students[infos[0]].append(int(sum(students[infos[0]])/3))

    studentsItem = students.items()

    # 对每门学科各自排序
    rankC = list(dict(sorted(studentsItem, key=lambda x: x[1][0], reverse=True)).keys())
    rankM = list(dict(sorted(studentsItem, key=lambda x: x[1][1], reverse=True)).keys())
    rankE = list(dict(sorted(studentsItem, key=lambda x: x[1][2], reverse=True)).keys())
    rankA = list(dict(sorted(studentsItem, key=lambda x: x[1][3], reverse=True)).keys())

    # 对每一个请求输出最高排名, 排序优先级ACME
    ranks = [rankA, rankC, rankM, rankE]
    mapper = {
        0: 'A',
        1: 'C',
        2: 'M',
        3: 'E'
    }
    for _ in range(checkNum):
        request = input()
        try:
            minIdx = min(enumerate(ranks), key=lambda x: x[1].index(request))[0]
            print(f"{ranks[minIdx].index(request) + 1} {mapper[minIdx]}")
        except ValueError:  # 没有这号学生
            print(f"N/A")


if __name__ == '__main__':
    summit()
