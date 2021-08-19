from typing import List, Dict
from functools import reduce


def get_paths(
    node: int,
    nodes: List[Dict],
    paths: List[Dict],
    stack: List[int],
    maxCapacity: int,
    indexOfProblemStation: int
):
    """
    该函数从有问题的节点出发，一直往回走走到发配站
    :param maxCapacity: 每个节点最大的容量
    :param indexOfProblemStation:
    :param node: 现在走到的节点
    :param nodes: 由dijkstra求出来的节点信息
    :param paths: 走到发配站之后，保存路径上的节点信息,{"path":[经过的节点1,经过的节点2,...], "bikeNumToSend": int, "bikeNumToTake"}
    :param stack: 记住之前的节点
    """
    stack.append(node)
    # 走到了发配站
    if len(nodes[node]["fathers"]) == 0:
        stack.pop(-1)  # 把发配站弹出
        # 现在路径上的单车数的和
        sumOfBikeNum = reduce(lambda a, b: a + nodes[b]["currentBikeNum"], stack, 0)
        # 现在路径上的节点数
        nodeNum = len(stack)

        # 证明需要带回去
        if nodes[indexOfProblemStation]["currentBikeNum"] == maxCapacity:
            bikeNumToTake = maxCapacity / 2
            bikeNumToSend = 0
        else:  # 为0
            bikeNumToTake = 0
            bikeNumToSend = nodeNum * maxCapacity / 2 - sumOfBikeNum

        paths.append({
            "path": stack[:],
            # 需要带过去的单车数量
            "bikeNumToSend": bikeNumToSend,
            # 需要带回来的单车的数量
            "bikeNumToTake": bikeNumToTake
        })
        # 弹出最顶的节点
        stack.pop(-1)
        return None

    for father in nodes[node]["fathers"]:
        get_paths(father, nodes, paths, stack, maxCapacity, indexOfProblemStation)


def summit():
    # maxCapacity,所有车站的最大容量
    # stationNum，车站的数量
    # indexOfProblemStation有问题的车的index，index从1开始编号
    # roadNum路径的数量
    maxCapacity, stationNum, indexOfProblemStation, roadNum = map(int, input().split())
    currentBikeNum: List[int] = [0]
    # 现在每个站点的单车的数量
    currentBikeNum.extend(map(int, input().split()))
    # 图的零阶矩阵存储,存放权值与路径,从1开始编号所以要加1，0是station的index
    graph = [[0] * (stationNum + 1) for _ in range(stationNum + 1)]
    # 建图
    for _ in range(roadNum):
        # station a,b 和这条路径的权值
        a, b, w = map(int, input().split())
        graph[a][b] = w
        graph[b][a] = w
    # dijkstra，从车站出发
    nodes = [{
        "fathers": [],  # 父亲节点们
        "weight": float("inf"),  # 现在的路径权值
        "index": idx,
        "currentBikeNum": bikeNum
    } for idx, bikeNum in enumerate(currentBikeNum)]

    # 未选点集
    # 将未选点集中的点加入已选点集，就相当于从未选点击中删去
    unSelectedInfos = nodes[1:]

    # 已选点集合
    # 用发配站初始化未选点集
    for index, weight in enumerate(graph[0]):
        # 存在一条边
        if weight != 0:
            nodes[index]["fathers"].append(0)
            nodes[index]["weight"] = graph[0][index]
    # 根节点的权值应该是0
    nodes[0]["weight"] = 0
    # 选择下一次前进的节点
    node = min(unSelectedInfos, key=lambda x: x["weight"])
    # 加入已选点集
    unSelectedInfos.remove(node)

    # 未选集合中还有元素
    while len(unSelectedInfos) > 0:
        # 根据选择的顶点更新已选点集
        for index, weight in enumerate(graph[node["index"]]):
            # 存在一条边
            if weight != 0:
                # 找到一条更短的路径
                if weight + node["weight"] < nodes[index]["weight"]:
                    nodes[index]["fathers"] = [node["index"]]
                    nodes[index]["weight"] = weight + node["weight"]
                    continue
                # 跟原来的路径代价相同
                if weight + node["weight"] == nodes[index]["weight"]:
                    nodes[index]["fathers"].append(node["index"])
                    continue
        # 选择下一次前进的node
        node = min(unSelectedInfos, key=lambda x: x["weight"])
        # 加入已选点集
        unSelectedInfos.remove(node)

    # 存放所有的路径
    paths = []
    # 现在走到的节点的下标
    node = indexOfProblemStation
    get_paths(node, nodes, paths, [], maxCapacity, node)
    result = min(paths, key=lambda x: (x["bikeNumToSend"], x["bikeNumToTake"]))
    print(f"{int(result['bikeNumToSend'])} {'->'.join(map(str, reversed(result['path'] + [0])))} {int(result['bikeNumToTake'])}")


if __name__ == '__main__':
    summit()
