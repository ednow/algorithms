from typing import List

def summit():
    nodeNum, edgeNum = map(int, input().split())
    # 邻接表表示法
    # nodes[idx] -> neighbor
    degrees: List[int] = [0 for _ in range(nodeNum + 1)]
    for _ in range(edgeNum):
        a, b = map(int, input().split())
        degrees[a] += 1
        degrees[b] += 1

    isNotEven = [i % 2 for i in degrees[1:]]
    notEvenNum = sum(isNotEven)
    print(" ".join(map(str, degrees[1:])))
    if notEvenNum == 0:
        print("Eulerian", end="")
        return None
    if notEvenNum == 2:
        print("Semi-Eulerian", end="")
        return None
    print("Non-Eulerian", end="")


if __name__ == '__main__':
    summit()
