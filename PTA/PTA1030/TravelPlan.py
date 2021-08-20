from typing import List, Dict


def get_paths(
        nodes: List[Dict],
        paths: List[List[int]],
        stack: List[int],
        source: int,
        destination: int,
        childAttr: str
):
    """
    通过dijkstra的结果信息表凭借出每一条路径
    :param source: 现在走到的点
    :param destination: 目标点
    # :param cost: 得到每条路的花费 cost可以在外部求
    :param nodes: dijkstra的结果信息表
    :param paths: [{"path", "cost"}]
    :param stack: 记住当前走过的节点
    """
    stack.append(source)
    if source == destination:
        paths.append(stack[:])
        stack.pop(-1)  # 弹出自己
        return None

    for child in nodes[source][childAttr]:
        get_paths(nodes, paths, stack, child, destination, childAttr)

    stack.pop(-1)


def get_cost(path: List[int], cost: List[List[int]]) -> int:
    """
    给定一条路径求这条路径的花费
    :param cost: 每条边的花费
    :param path: 路径
    """
    result = 0
    for a, b in zip(path[:-1], path[1:]):
        result += cost[a][b]
    return result


def dijkstra(nodes: List[Dict], source: int, graph: List[List[int]]):
    """
    对graph按照source求dijkstra
    :param nodes: 所有的节点
    :param source: 源
    :param graph: 边权值的图
    """
    nodes[source]["weight"] = 0
    unSelectedNodes = nodes[:]
    while len(unSelectedNodes) != 0:  # dijkstra
        node = min(unSelectedNodes, key=lambda x: x["weight"])
        for idx, weight in enumerate(graph[node["index"]]):
            # 存在一条路径
            if weight != 0:
                # 找到一条更短的路径
                if weight + node["weight"] < nodes[idx]["weight"]:
                    nodes[idx]["weight"] = weight + node["weight"]
                    nodes[idx]['fathers'] = [node["index"]]
                # 跟原来路径的长度相同
                elif weight + node["weight"] == nodes[idx]["weight"]:
                    nodes[idx]['fathers'].append(node["index"])
        unSelectedNodes.remove(node)


def summit():
    # cityNum城市（点）的数量,
    # roadNum道路（边）数量,
    # source, 起点
    # destination,终点
    cityNum, roadNum, source, destination = map(int, input().split())

    # 邻接矩阵表示法,边的长度为0表示无法到达
    # 边的长度
    graph = [[0] * cityNum for _ in range(cityNum)]
    # 边的花费
    cost = [[0] * cityNum for _ in range(cityNum)]
    # 读取边
    for _ in range(roadNum):
        a, b, d, c = map(int, input().split())
        graph[a][b] = d
        graph[b][a] = d
        cost[a][b] = c
        cost[b][a] = c
    # 维护dijkstra求最短路劲时所有节点的父亲
    nodes = [{
        "fathers": [],
        "index": idx,
        "weight": float("inf")  # 累计路径长度
    } for idx in range(cityNum)]

    # 反向求dijkstra，然后就可以正向求路径了
    dijkstra(nodes, destination, graph)

    # 存放source到destination的所有最短路径
    paths = []
    # 其实就是个dfs，反向dijkstra要交换回来
    get_paths(nodes, paths, [], source, destination, "fathers")
    # 多条最短路径，选择最便宜的
    result = min(paths, key=lambda x: get_cost(x, cost))
    # 输出结果
    # 由于是反向求dijkstra,最终的权重要用source来求
    print(f"{' '.join(map(str, result))} {nodes[source]['weight']} {get_cost(result, cost)}")


if __name__ == '__main__':
    summit()
