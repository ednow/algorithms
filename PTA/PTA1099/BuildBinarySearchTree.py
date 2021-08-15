from __future__ import annotations
from typing import List, Iterable


# 二叉树的链式表示法
class Node:
    def __init__(self, index: int = None):
        self.label = None
        self.index = index
        self.right = None
        self.left = None

    # @property
    # def iter_children(self) -> Iterable[Node]:
    #     """
    #     返回一个左孩子的迭代器
    #     :return:
    #     """
    #     return filter(lambda x: x is not None, [self.left, self.right])

    @property
    def value(self) -> str:
        return f"{self.index},{self.label}"


try:
    import ppbtree
    def print_tree(root:Node):
        """
        他的横向打印不符合我的理解
        :param root: 树
        """
        ppbtree.print_tree(root, left_child='right', right_child='left')
except Exception:
    pass


def count_node_num(root: Node) -> int:
    """
    给定一棵树，计算这棵树的节点的数量
    :param root:
    :return:
    """
    if root is None:
        return 0

    return sum(count_node_num(children) for children in [root.left, root.right]) + 1


def fill_values(root: Node, nums: List[int]):
    """
    给定一串节点nums,找到root对应的值填进去，如果nums中还有值继续填补
    :param root: 需要填补的根节点
    :param nums: 需要填补的节点们
    """
    if len(nums) == 0:
        return None

    # 计算左子树节点的数量
    leftNums = count_node_num(root.left)
    # 填补左子树
    fill_values(root.left, nums[:leftNums])
    # 填补root的value
    root.label = nums[leftNums]
    # 填补左子树
    fill_values(root.right, nums[leftNums+1:])


def level_traversal(root: Node, result: List[int]):
    q = [root]
    while len(q) > 0:
        if q[0].left is not None:
            q.append(q[0].left)
        if q[0].right is not None:
            q.append(q[0].right)
        result.append(q.pop(0).label)


def summit():
    nodesNum: int = int(input())
    nodes: List[Node] = [Node(i) for i in range(nodesNum)]
    # 读取数据构建空树的连接情况
    for idx in range(nodesNum):
        nums = list(map(int, input().split()))
        # 左子树有节点
        if nums[0] != -1:
            nodes[idx].left = nodes[nums[0]]

        if nums[1] != -1:
            nodes[idx].right = nodes[nums[1]]
    # globals()["ROOT"] = nodes[0] # debug
    nums = list(map(int, input().split()))
    nums.sort()
    fill_values(nodes[0], nums)
    # 存放层次遍历的结果
    result: List[int] = []
    level_traversal(nodes[0], result)
    print(" ".join(map(str, result)))


if __name__ == '__main__':
    summit()
