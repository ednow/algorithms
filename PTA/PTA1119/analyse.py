from .PreAndPostOrderTraversals import Node
from typing import List
import unittest
import pptree


def summit():
    nodesNum: int = int(input())
    preOrderSeq: List[int] = list(map(int, input().split()))
    postOrderSeq: List[int] = list(map(int, input().split()))
    nodes: List[Node] = [Node(i) for i in range(0, nodesNum + 1)]

    # 模拟出入站能得到一颗树
    s = [preOrderSeq[0]]
    preOrderIdx: int = 1
    postOrderIdx: int = 0
    while len(s) > 0:
        if s[-1] == postOrderSeq[postOrderIdx]:
            postOrderIdx += 1
            s.pop(-1)
        else:
            s.append(preOrderSeq[preOrderIdx])
            preOrderIdx += 1
            nodes[s[-2]].children.append(nodes[s[-1]])

    pptree.print_tree(nodes[1], horizontal=False)


if __name__ == '__main__':
    summit()

