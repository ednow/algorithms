from typing import List


# 二叉树的链式存储结构的节点
class Node:
    def __init__(self, label: int):
        # left左孩子，label该节点的编号，right有孩子
        self.left = None
        self.label = label
        self.right = None


def invert_tree(treeDesByNodeList: List[Node]):
    """
    将树反转，将树的左右孩子交换
    :param treeDesByNodeList: 节点列表
    """
    for idx in range(len(treeDesByNodeList)):
        treeDesByNodeList[idx].left, treeDesByNodeList[idx].right = treeDesByNodeList[idx].right, treeDesByNodeList[idx].left


def inorder_traversal(root: Node, result: List[int]):
    """
    给定树的根节点，对树进行中序遍历
    :param result: 存放结果的字符串
    :param root: 树的根节点
    """
    # 根节点为空直接返回
    if root is None:
        return None

    inorder_traversal(root.left, result)
    result.append(root.label)
    inorder_traversal(root.right, result)


def level_traversal(root: Node) -> List[int]:
    """
    给定树的根节点，对树进行层次遍历
    :param root: 树的根节点
    """
    q = [root]
    result: List[int] = []
    while len(q) > 0:
        # 孩子节点
        if q[0].left is not None:
            q.append(q[0].left)

        if q[0].right is not None:
            q.append(q[0].right)

        result.append(q.pop(0).label)

    return result


def summit():
    # 节点数
    nodesNum = int(input())
    # 参考树的双亲表示法设计的二叉树的双亲表示法，用来找根节点
    # tree described by Parents
    treeDesByParents: List[int] = [-1 for _ in range(nodesNum)]
    # 二叉树的链式存储结构的节点列表
    # tree described by Linked Node, nodes are stored in List
    treeDesByNodeList: List[Node] = [Node(i) for i in range(nodesNum)]
    for idx in range(nodesNum):
        strings = input().split()
        # 左孩子不为空
        if strings[0] != '-':
            treeDesByNodeList[idx].left = treeDesByNodeList[int(strings[0])]
            treeDesByParents[int(strings[0])] = idx
        # 右孩子不为空
        if strings[1] != '-':
            treeDesByNodeList[idx].right = treeDesByNodeList[int(strings[1])]
            treeDesByParents[int(strings[1])] = idx

    # 找到根节点
    root = 0
    while treeDesByParents[root] != -1:
        root = treeDesByParents[root]

    # 将树的左右孩子交换
    invert_tree(treeDesByNodeList)

    print(" ".join(map(str, level_traversal(treeDesByNodeList[root]))))
    inorder = []
    inorder_traversal(treeDesByNodeList[root], inorder)
    print(" ".join(map(str, inorder)))


if __name__ == '__main__':
    summit()
