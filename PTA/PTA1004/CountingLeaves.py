import unittest
from typing import Dict, List, Tuple
import queue


def solution(tree: Dict[int, List[int]]) -> str:
    """
    :param tree: 孩子表示法：见readme
    :return:
    """
    q = queue.Queue()
    answer = dict()
    result = []
    childLevel = 0
    q.put((1, 1))  # 根节点进入队列,(节点编号，节点所在层号)
    # 进行层次遍历, 返回每一层的叶子节点数
    while not q.empty():
        head = q.get()  # 队列的头元素
        if len(tree[head[0]]) == 0:  # 检查头元素是不是叶子节点
            emptyNum = answer.get(head[1], 0)
            answer[head[1]] = emptyNum + 1  # 该层叶子节点数+1
        else:  # 让头元素的孩子节点进入队列
            childLevel = head[1] + 1
            for child in tree[head[0]]:
                q.put((child, childLevel))
    for i in range(1, childLevel+1):
        result.append(str(answer.get(i, 0)))
    if childLevel == 0:
        result = ["1"]
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
    print(solution(tree), end="\n")


if __name__ == '__main__':
    summit()

