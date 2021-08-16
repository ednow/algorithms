"""
copied from pta1020
"""
from typing import List, Dict, Union
import queue


# 二叉树的链式存储结构
class Node:
    __slots__ = 'left', 'right', 'data'

    @property
    def value(self):
        return self.data


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


def attach_node(father: Node, postOrderList: List[int], inOrderList: List[int], isLeft: bool):
    """
    递归将节点附着到树上
    :param father: 当前要附着的节点的父亲节点
    :param postOrderList: 后序序列
    :param inOrderList: 中序序列
    :param isLeft: 现在准备附着的节点是附着到父亲节点左孩子还是右孩子
    """
    if len(postOrderList) == 0:
        return 0

    # 后序的最后一个是根节点
    root = Node()
    root.right = None
    root.data = postOrderList[-1]
    root.left = None

    # 根据需求附着节点
    if isLeft:
        father.left = root
    else:
        father.right = root

    # 根节点所在中序序列中的位置
    rootIndex = inOrderList.index(postOrderList[-1])

    # 根据中序左孩子的列表扫描，后序序列左孩子的位置
    rightestOfLeft = -1  # 根节点左孩子的最右边的孩子的下标
    for i in range(len(inOrderList[:rootIndex])):
        if postOrderList[i] in inOrderList[:rootIndex]:
            rightestOfLeft += 1

    # 将左孩子附着到根节点
    attach_node(root, postOrderList[0: rightestOfLeft + 1], inOrderList[:rootIndex], isLeft=True)
    # 将右孩子附着到根节点
    attach_node(root, postOrderList[rightestOfLeft + 1: -1], inOrderList[rootIndex + 1:], isLeft=False)


def zigzag_level_traversal(root: Node) -> List[int]:
    """
    根据给定的树的根节点，对树进行层次遍历
    :param root: 树的根节点
    """
    q = queue.Queue()
    result = []
    nodesByLevel: Dict[int, List[int]] = dict()
    q.put({
        "level": 1,
        "node": root
    })
    while not q.empty():
        item: Dict[str, Union[int, Node]] = q.get()
        nodesByLevel[item["level"]] = nodesByLevel.get(item["level"], [])
        nodesByLevel[item["level"]].append(item["node"].data)
        # 压入左孩子
        if item["node"].left is not None:
            q.put({"level": item["level"] + 1, "node": item["node"].left})

        # 压入左孩子
        if item["node"].right is not None:
            q.put({"level": item["level"] + 1, "node": item["node"].right})

    result.extend(nodesByLevel[1])
    # 从第三层开始隔一层反转
    for level in sorted(nodesByLevel.keys())[1:]:
        if level % 2 == 1:
            result.extend(reversed(nodesByLevel[level]))
        else:
            result.extend(nodesByLevel[level])
    return result


def summit():
    input()
    inOrderList = list(map(int, input().split()))
    postOrderList = list(map(int, input().split()))

    # 后序的最后一个是根节点
    root = Node()
    root.right = None
    root.data = postOrderList[-1]
    root.left = None

    # 根节点所在中序序列中的位置
    rootIndex = inOrderList.index(postOrderList[-1])

    # 根据中序左孩子的列表扫描，后序序列左孩子的位置
    rightestOfLeft = -1  # 根节点左孩子的最右边的孩子的下标
    for i in range(len(inOrderList[:rootIndex])):
        if postOrderList[i] in inOrderList[:rootIndex]:
            rightestOfLeft += 1

    # 将左孩子附着到根节点
    attach_node(root, postOrderList[0: rightestOfLeft + 1], inOrderList[:rootIndex], isLeft=True)
    # 将右孩子附着到根节点
    attach_node(root, postOrderList[rightestOfLeft + 1: -1], inOrderList[rootIndex + 1:], isLeft=False)

    print(" ".join(map(str, zigzag_level_traversal(root))))


if __name__ == '__main__':
    summit()
