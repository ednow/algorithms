from __future__ import annotations
from typing import List, Iterable, Union


# 节点的链式存储结构
class Node:
    def __init__(self, index: int, label: int):
        self.index = index
        # 节点的值,特殊的节点"null"label为1吧
        self.label = label
        self.left = None
        self.right = None

    @property
    def color(self):
        if self.label > 0:
            return "black"
        else:
            return "red"

    # 大的在左边
    # 大于等于在左边把实现的比较改为 >=即可
    # def __gt__(self, other: Node) -> bool:
    #     return abs(self.label) > abs(other.label)

    def __lt__(self, other):
        # 注意比较的时候要加绝对值
        return abs(self.label) < abs(other.label)

    @property
    def is_leaf(self) -> bool:
        """
        这个节点是不是叶子节点
        :return:
        """
        return not any([self.left, self.right])

    @property
    def is_all_child_black(self) -> bool:
        """
        检查是不是孩子节点都是黑色的
        """
        return all(i.is_black for i in filter(lambda x: x is not None, [self.right, self.left]))

    @property
    def is_red(self) -> bool:
        return self.label < 0

    @property
    def is_black(self) -> bool:
        return self.label > 0

    @property
    def value(self):
        return f"({self.label}, {self.color})"


# debug
try:
    import ppbtree


    def print_tree(root: Node):
        """
        他的横向打印不符合我的理解
        :param root: 树
        """
        ppbtree.print_tree(root, left_child='right', right_child='left')
except Exception:
    pass


def attach_node(root: Node, preOrderSeq: List[Node]):
    """
    递归将节点列表里面的节点依附上去
    :param root: 根节点
    :param preOrderSeq: 先序节点列表
    """
    # 递归中止没有节点可以依附了
    if len(preOrderSeq) == 0:
        return None

    maxLeftIdx = -1
    # 找到左子树最大的下标
    for idx in range(len(preOrderSeq)):
        if preOrderSeq[idx] < root:
            maxLeftIdx = idx
    # 确实有左孩子
    if maxLeftIdx != -1:
        root.left = preOrderSeq[0]
    # 不是全都是左孩子
    if maxLeftIdx != len(preOrderSeq) - 1:
        root.right = preOrderSeq[maxLeftIdx + 1]

    attach_node(root.left, preOrderSeq[1:maxLeftIdx + 1])
    attach_node(root.right, preOrderSeq[maxLeftIdx + 2:])


def add_nil(nodes: List[Node]):
    """
    所有的空姐点都被替换成"null"
    :param nodes:
    """
    idx = len(nodes)
    for node in nodes[:]:
        if node.left is None:
            node.left = Node(idx, 1)
            idx += 1
            nodes.append(node.left)

        if node.right is None:
            node.right = Node(idx, 1)
            idx += 1
            nodes.append(node.right)


def check_red_black_tree() -> str:
    """
    检查输入的是不是红黑树,是返回“Yes”, 不是返回“No”
    """
    nodesNum: int = int(input())
    nodes: List[Node] = [Node(idx, num) for idx, num in enumerate(map(int, input().split()))]
    # 检查根节点是不是红色
    if nodes[0].is_red:
        return "No"

    attach_node(nodes[0], nodes[1:])  # 要先attach

    add_nil(nodes)

    # 双亲表示法,方便求路径
    fathers: List[int] = [-1 for _ in range(len(nodes))]
    for node in nodes:
        if not (node.left is None):
            fathers[node.left.index] = node.index
        if not (node.right is None):  # ~~常犯小错误, is not xxx 通常是not(is xxx),~~ 应该是可以的
            fathers[node.right.index] = node.index

    # 叶子节点
    # leafNodes: Iterable[Node] = filter(lambda x: x.is_leaf, nodes)
    # 从叶子节点一直到根节点,一路上黑色的节点的数量
    blackNodesOnPath = []
    for leaf in filter(lambda x: x.is_leaf, nodes):
        blackNum = 0
        father = leaf.index
        while father != -1:
            if nodes[father].is_black:
                blackNum += 1
            father = fathers[father]  # 死循环

        blackNodesOnPath.append(blackNum)

    if len(set(blackNodesOnPath)) != 1:
        return "No"

    # 检查所有红色节点的孩子是不是黑色
    if not all(x.is_all_child_black for x in filter(lambda x: x.is_red, nodes)):
        return "No"

    return "Yes"


def summit():
    print("\n".join(check_red_black_tree() for _ in range(int(input()))))


if __name__ == '__main__':
    summit()
