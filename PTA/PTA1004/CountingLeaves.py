import unittest
from typing import Dict, List, Tuple
import queue


def solution(tree: Dict[int, List[int]]) -> str:
    q = queue.Queue()
    answer = dict()
    result = []
    childLevel = 0
    q.put((1, 1))  # 根节点进入队列,(节点编号，节点所在层号)
    while not q.empty():
        head = q.get()
        if len(tree[head[0]]) == 0:
            emptyNum = answer.get(head[1], 0)
            answer[head[1]] = emptyNum + 1
        else:
            childLevel = head[1] + 1
            for child in tree[head[0]]:
                q.put((child, childLevel))
    for i in range(1, childLevel+1):
        result.append(str(answer.get(i, 0)))
    return " ".join(result)


def get_nodes_and_not_leaves_num(string: str) -> List[int]:
    """
    :param string: "节点数 叶子节点数"
    :return: [节点数, 叶子节点数]
    """
    return list(map(int, string.split()))


def get_children(string: str) -> Tuple[int, List[int]]:
    """
    :param string: "ID K ID[1] ID[2] ... ID[K]"
    :return: 父亲节点，[ID[1] ID[2] ... ID[K]]
    """
    nodes = list(map(int, string.split()))
    return nodes[0], nodes[2:]


def summit() -> str:
    nodes, notLeaves = get_nodes_and_not_leaves_num(input())
    tree = {
        i: [] for i in range(nodes+1)
    }
    while notLeaves > 0:
        parent, children = get_children(input())
        tree[parent].extend(children)
        notLeaves -= 1
    return solution(tree)


class TestPTA1004(unittest.TestCase):
    def setUp(self) -> None:
        import json
        with open("data.json", encoding="utf-8", mode="r") as f:
            self.testCases = json.load(f)

    def test_pta1004(self):
        for idx, testCase in enumerate(self.testCases):
            a, answer = list(testCase.values())
            lines = a.split("\n")
            nodes, notLeaves = get_nodes_and_not_leaves_num(lines[0])
            tree = {
                i: [] for i in range(nodes + 1)
            }
            for line in lines[1:]:
                parent, children = get_children(line)
                tree[parent].extend(children)
            result = solution(tree)
            assert answer == result, f"{answer}, {result}"


if __name__ == '__main__':
    print(summit(), end="\n")
