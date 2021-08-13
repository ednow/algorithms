from typing import List
from math import log, ceil


# 二叉树的链式存储结构
class Node:
    def __init__(self, label: int = None):
        self.label = label
        self.left = None
        self.right = None


def insert_nodes(root: Node, nums: List[int]):
    """
    向二叉排序中添加节点
    :param root: 二叉排序树的根节点
    :param nums: 待插入的序列
    """
    numLen = len(nums)
    # 没有待插入的节点
    if numLen == 0:
        return None

    # 只有一个节点
    if numLen == 1:
        # 总的列表里面就只有一个节点
        if root.label is None:
            root.label = nums[0]
        else:
            # 总的列表长度大于等于3,通过递归来到了这个位置
            root.left = Node(nums[0])
        return None

    # 只有两个节点
    if numLen == 2:
        if root.label is None:
            root.label = nums[1]
        else:
            root.right = Node(nums[1])
        root.left = Node(nums[0])
        return None

    # 只有三个节点
    if numLen == 3:
        if root.label is None:
            root.label = nums[1]
            root.right = Node(nums[2])
            root.left = Node(nums[0])
        else:
            n = Node(nums[1])
            n.left = Node(nums[0])
            n.right = Node(nums[2])
            if n.label >= root.label:
                root.right = n
            else:
                root.left = n
        return None

    # 算出来剩下树的高度
    h = ceil(log((numLen + 1) + 1, 2))
    # 如果要构成一棵满二叉树还差几个元素
    emptyElem = 2 ** h - 1 - numLen
    # 左子树的数量
    rightNum = -1
    # 最后一层在左右子树的分布情况是怎么样的
    # 2 ** (h - 1) / 2 = 2 ** (h - 2)
    if emptyElem >= 2 ** (h - 2):
        rightNum = 2 ** (h - 2) - 1
    else:
        # 2 ** (h - 2) - 1 + 2 ** (h - 1) / 2 - emptyElem
        # = 2 ** (h - 1) - 1 - emptyElem
        rightNum = 2 ** (h - 1) - 1 - emptyElem

    root.label = nums[-rightNum-1]
    root.left = Node()
    root.right = Node()
    insert_nodes(root.left, nums[:-rightNum-1])
    insert_nodes(root.right, nums[-rightNum:])


def summit():
    input()
    nums: List[int] = list(map(int, input().split()))
    nums.sort()
    root = Node()
    insert_nodes(root, nums)

    result: List[int] = []
    q: List[Node] = [root]
    while len(q) > 0:
        if q[0].left is not None:
            q.append(q[0].left)
        if q[0].right is not None:
            q.append(q[0].right)
        result.append(q.pop(0).label)

    print(" ".join(map(str, result)))


if __name__ == '__main__':
    summit()
