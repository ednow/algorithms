from typing import List
from collections import Counter


def summit():
    nodeNum, edgeNum = map(int, input().split())
    # 邻接表表示法
    # nodes[idx] -> neighbor
    nodes: List[List[int]] = [[] for _ in range(nodeNum + 1)]
    for _ in range(edgeNum):
        a, b = map(int, input().split())
        nodes[a].append(b)
        nodes[b].append(a)

    degrees: List[int] = [len(i) for i in nodes[1:]]
    isEven = [i % 2 == 0 for i in degrees]
    evenCounter = dict(Counter(isEven))
    print(" ".join(map(str, degrees)))

    if evenCounter[True] == len(degrees):
        print("Eulerian", end="")
        return None

    if evenCounter[False] == 2:
        print("Semi-Eulerian", end="")
        return None

    print("Non-Eulerian", end="")


if __name__ == '__main__':
    summit()
