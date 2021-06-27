import unittest
from typing import Dict, List, Tuple


def solution(graph: List[List[int]], source: int, destination: int, teams: Dict[int, int]) -> str:
    nodes = len(graph)
    infos = [
        [False] * nodes,  # 访问位
        [float("inf")] * nodes,  # 最短路径的长度
        # [None] * nodes,  # 最短路径的父亲节点
        [0] * nodes,  # 多少条最短路径
        [0] * nodes  # 最大的资源数
    ]

    infos[0][source] = True  # 起点的访问位为True
    infos[1][source] = 0  # 起点的最短路径的长度为0
    infos[3][source] = teams[source]  # 起点的最大资源数为其自己的资源

    # 现在扫描的节点
    now = source

    # 还有未访问的点
    while not all(infos[0]):
        # for i in zip(*infos) 转置的效率会怎么样
        # 扫描现在节点的邻居
        for neighbor in range(nodes):
            # 存在一条边
            if graph[now][neighbor] != 0:
                temp = infos[1][now] + graph[now][neighbor]
                if infos[1][neighbor] > temp:  # 当前的路径更小，替换信息表中的路径
                    infos[1][neighbor] = temp
                    totalTeams = infos[3][now] + teams[neighbor]
                    if infos[3][neighbor] < totalTeams:  # 如果这条最短路径上的物资更多
                        infos[3][neighbor] = totalTeams
                elif infos[1][neighbor] == temp and infos[0][neighbor] is True:  # 如果相等且已经访问，最短路径数+1
                    infos[2][neighbor] += 1

        #  找到当前未访问且路径最短的节点
        minIdx = -1
        minWeight = float("inf")
        for i in range(nodes):
            if (infos[0][i] is False) and (infos[1][i] < minWeight):
                minIdx = i
                minWeight = infos[1][i]

        # 更新当前的扫描头
        infos[0][minIdx] = True
        now = minIdx

    return f"{infos[2][destination]} {infos[3][destination]}"


def get_cities_roads_source_destination(string: str) -> List[int]:
    """
    :param string: "citiesNum roadsNum source destination"
    :return: [citiesNum, roadsNum, source, destination]
    """
    return list(map(int, string.split()))


def get_teams_size(string: str) -> Dict[int, int]:
    """
    :param string: "team1 team2 ... teamN"
    :return: {team_i: size}
    """
    return {
        idx: int(i) for idx, i in enumerate(string.split())
    }


def add_edge(graph: List[List[int]], string: str) -> None:
    """
    :param graph: 邻接矩阵表示的图
    :param string: "node1 node2 weight"
    """
    edge = list(map(int, string.split()))
    graph[edge[0]][edge[1]] = edge[2]
    graph[edge[1]][edge[0]] = edge[2]


def summit() -> str:
    cities,  roads, source, destination = get_cities_roads_source_destination(input())
    graph = [[0] * cities] * cities
    teams = get_teams_size(input())
    while roads > 0:
        add_edge(graph, input())
        roads -= 1
    return solution(graph, source, destination, teams)


class TestPTA1003(unittest.TestCase):
    def setUp(self) -> None:
        import json
        with open("data.json", encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)

    def modify(self, a):
        a["1"] = 1

    def test_modify(self):
        a = {}
        self.modify(a)
        assert a["1"] == 1, f"{a['1']}"

    def test_pta1003(self):
        for idx, testCase in enumerate(self.testCases):
            a, answer = list(testCase.values())
            lines = a.split("\n")
            cities, roads, source, destination = get_cities_roads_source_destination(lines[0])
            graph = [[0] * cities] * cities
            teams = get_teams_size(lines[1])
            for i in lines[2:]:
                add_edge(graph, i)
                roads -= 1
            result = solution(graph, source, destination, teams)
            assert answer == result, f"{answer}, {result}"


if __name__ == '__main__':
    print(summit(), end="\n")
