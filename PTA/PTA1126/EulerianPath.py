from typing import List
from collections import Counter


def summit():
    nodeNum, edgeNum = map(int, input().split())
    # 邻接表表示法
    # nodes[idx] -> neighbor
    degrees: List[int] = [0 for _ in range(nodeNum + 1)]
    for _ in range(edgeNum):
        a, b = map(int, input().split())
        degrees[a] += 1
        degrees[b] += 1

    isEven = [i % 2 == 0 for i in degrees[1:]]
    evenCounter = Counter(isEven)
    print(" ".join(map(str, degrees[1:])))
    try:
        if evenCounter[True] == len(isEven):
            print("Eulerian", end="")
            return None
    except Exception:
        pass
    if evenCounter[False] == 2:
        print("Semi-Eulerian", end="")
        return None

    print("Non-Eulerian", end="")


if __name__ == '__main__':
    summit()
