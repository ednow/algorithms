from typing import List, Callable, Dict, Set
from copy import deepcopy


def dfs(start: int, graph: List[List[bool]], isVisited: List[bool]):
    """
    对图进行一次dfs
    :param isVisited: 某个边的某个临界点是否被访问
    :param start: 开始的节点
    :param graph: 图
    """
    isVisited[start] = True
    for idx, edge in enumerate(graph[start]):
        # 需要标记某个是否被访问
        if edge and not isVisited[idx]:
            dfs(idx, graph, isVisited)


def occupy_city(node: int, graph: List[List[bool]], nodeNum: int) -> int:
    """

    :param nodeNum: 一共有多少城市
    :param node: 被占领的城市
    :param graph: map
    :return: 需要修的路的数量
    """
    graph = deepcopy(graph)
    # 将边去掉
    for i in range(nodeNum):
        graph[i][node] = False
        graph[node][i] = False

    # 进行dfs的次数
    dfsTimes = -1

    nodes = set(i for i in range(1, nodeNum + 1))
    nodes -= {0, node}
    isVisited = [False for _ in range(nodeNum + 1)]
    isVisited[node] = True
    isVisited[0] = True
    while not all(isVisited):
        dfs(nodes.pop(), graph, isVisited)
        dfsTimes += 1

    return dfsTimes


def summit():
    nodeNum, edgeNum, queryNum = map(int, input().split())
    graph: List[List[bool]] = [[False] * (nodeNum + 1) for _ in range(nodeNum + 1)]
    for _ in range(edgeNum):
        a, b = map(int, input().split())
        graph[a][b] = True
        graph[b][a] = True
    # 存放结果
    result: List[int] = []

    for node in map(int, input().split()):
        result.append(occupy_city(node, graph, nodeNum))

    print("\n".join(map(str, result)))


if __name__ == '__main__':
    summit()
