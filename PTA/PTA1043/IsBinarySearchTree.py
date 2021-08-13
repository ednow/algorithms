from typing import List


# 链式存储结构
class Node:
    def __init__(self, label: int):
        self.label = label
        self.right = None
        self.left = None

    def __ge__(self, other):
        return self.label >= other.label


def preorder_traversal(root: Node, result: List[int]):
    """
    前序遍历二叉树
    :param root: 二叉树的根节点
    :param result: 后序序列存放的列表
    :return:
    """
    if root is None:
        return None

    result.append(root.label)
    preorder_traversal(root.left, result)
    preorder_traversal(root.right, result)


def postorder_traversal(root: Node, result: List[int]):
    """
    后序遍历二叉树
    :param root: 二叉树的根节点
    :param result: 后序序列存放的列表
    :return:
    """
    if root is None:
        return None

    postorder_traversal(root.left, result)
    postorder_traversal(root.right, result)
    result.append(root.label)


def insert_node(root: Node, node: Node, swap: bool):
    """

    :param root: 二叉排序树的根节点
    :param node: 要插入到二叉排序树的节点
    :param swap: 是不是镜像二叉排序树
    """
    if swap:
        # 大的放在左边
        if node >= root:
            if root.left is None:
                root.left = node
            else:
                insert_node(root.left, node, swap)
        # 小的放右边
        else:
            if root.right is None:
                root.right = node
            else:
                insert_node(root.right, node, swap)
    else:
        # 大的放在右边
        if node >= root:
            if root.right is None:
                root.right = node
            else:
                insert_node(root.right, node, swap)
        # 小的放左边
        else:
            if root.left is None:
                root.left = node
            else:
                insert_node(root.left, node, swap)


def summit():
    # nodeNums = int(input())
    input()
    nums = list(map(int, input().split()))
    # 节点列表
    nodes: List[Node] = [Node(i) for i in nums]
    # 按照镜像bst来存?
    swap = False
    if nodes[1] >= nodes[0]:
        swap = True

    root = nodes[0]
    # 建树
    for node in nodes[1:]:
        insert_node(root, node, swap)

    result = []
    preorder_traversal(root, result)
    if result != nums:
        print("NO")
        return None

    result = []
    postorder_traversal(root, result)
    print(f"YES\n{' '.join(map(str, result))}")


if __name__ == '__main__':
    summit()
