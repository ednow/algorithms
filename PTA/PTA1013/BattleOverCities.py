from typing import List, Callable, Dict, Set
from copy import deepcopy


def dfs(start: int, graph: List[List[bool]], result: Set, isVisited: List[List[bool]]):
    """
    对图进行一次dfs
    :param isVisited: 某个边的某个临界点是否被访问
    :param start: 开始的节点
    :param graph: 图
    :param result: 存放遍历过的节点
    """
    result.add(start)
    for idx, edge in enumerate(graph[start]):
        # 需要标记某个是否被访问
        if edge and not isVisited[start][idx]:
            isVisited[start][idx] = True
            dfs(idx, graph, result, isVisited)


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
    nodes.remove(node)
    while len(nodes) > 0:
        nodesToRemove = set()
        isVisited = [[False] * (nodeNum + 1) for _ in range(nodeNum + 1)]
        dfs(nodes.pop(), graph, nodesToRemove, isVisited)
        nodes -= nodesToRemove
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
