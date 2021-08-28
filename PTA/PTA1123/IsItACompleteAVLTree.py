from __future__ import annotations
from typing import List


class Node:
    def __init__(self, label: int):
        self.label = label
        self.bf = 0
        self.left = None
        self.right = None

    def __ge__(self, other: Node):
        return self.label >= other.label

    def __gt__(self, other: Node):
        return self.label > other.label

    def __le__(self, other):
        return self.label <= other.label

    def __lt__(self, other):
        return self.label <= other.label


def right_rotate(root: Node):
    """
    向右旋转

    新节点插入到了左子树的左子树上只会调用这个方法
    :param root: 需要旋转的节点
    """
    leftOfRoot: Node = root.left
    root.left = leftOfRoot.left
    leftOfRoot.left = leftOfRoot.right
    root.right = leftOfRoot
    leftOfRoot.label, root.label = root.label, leftOfRoot.label


def left_rotate(root: Node):
    """
    向左旋转

    新节点插入到了右子树的右子树上只会调用这个方法
    :param root: 需要旋转的节点
    """
    rightOfRoot: Node = root.right
    root.right = rightOfRoot.right
    rightOfRoot.left = rightOfRoot.left
    root.left = rightOfRoot
    rightOfRoot.label, root.label = root.label, rightOfRoot.label


def left_balance(root: Node):
    """

    :param root:
    :return:
    """
    leftOfRoot: Node = root.left
    if leftOfRoot.bf == 1:
        right_rotate(root)
        leftOfRoot.bf = root.bf = 0
        return None
    rightOfLeft: Node = leftOfRoot.right

    # 树中只有abc三个节点
    if rightOfLeft.bf == 0:
        leftOfRoot.bf = root.bf = rightOfLeft.bf = 0
    # 插入到了rightOfLeft的左子树上
    elif rightOfLeft.bf == 1:
        leftOfRoot.bf = rightOfLeft.bf = 0
        root.bf = -1
    # 插入到了rightOfLeft的右子树上
    elif rightOfLeft.bf == -1:
        root.bf = rightOfLeft.bf = 0
        leftOfRoot.bf = 1

    left_rotate(rightOfLeft)
    right_rotate(rightOfLeft)


def right_balance(root: Node):
    """

    :param root:
    :return:
    """
    rightOfRoot: Node = root.right
    if rightOfRoot.bf == 1:
        left_rotate(root)
        rightOfRoot.bf = root.bf = 0
        return None
    leftOfRight: Node = rightOfRoot.right

    # 树中只有abc三个节点
    if leftOfRight.bf == 0:
        rightOfRoot.bf = root.bf = leftOfRight.bf = 0
    # 插入到了leftOfRight的左子树上
    elif leftOfRight.bf == 1:
        root.bf = leftOfRight.bf = 0
        rightOfRoot.bf = -1
    # 插入到了leftOfRight的右子树上
    elif leftOfRight.bf == -1:
        rightOfRoot.bf = leftOfRight.bf = 0
        root.bf = 1

    right_rotate(leftOfRight)
    left_rotate(leftOfRight)


def insert_node(root: Node, child: Node) -> bool:

    if child > root:
        if root.right is None:
            root.right = child
            taller = True
        else:
            taller = insert_node(root.right, child)
        if taller:
            # 原本右子树就高1，现在高2
            if root.bf == -1:
                right_balance(root)
                return False

            # 原本左子树高1，现在平衡
            if root.bf == 1:
                root.bf = 0
                return False

            if root.bf == 0:
                root.bf = -1
                return True
    else:
        if root.left is None:
            root.left = child
            taller = True
        else:
            taller = insert_node(root.left, child)
        if taller:
            if root.bf == 1:
                left_balance(root)
                return False

            if root.bf == -1:
                root.bf = 0
                return False

            if root.bf == 0:
                root.bf = 1
                return True


def summit():
    input()
    nums: List[int] = list(map(int, input().split()))
    root: Node = Node(nums[0])
    for num in nums[1:]:
        insert_node(root, Node(num))

    # 层次遍历统计每一层的数量
    levelToNum = dict()
    q = [{"level": 1, "node": root}]
    traversal: List[int] = []
    while len(q) > 0:
        head = q.pop(0)
        levelToNum["level"] = levelToNum.get(head["level"], 0) + 1
        traversal.append(head["node"].label)
        if head["node"].left is not None:
            q.append({
                "level": head["level"] + 1,
                "node": head["node"].left
            })
        if head["node"].right is not None:
            q.append({
                "level": head["level"] + 1,
                "node": head["node"].right
            })
    if all(2**(key-1) == value for key, value in traversal):
        isComplete = "YES"
    else:
        isComplete = "NO"

    print(f"{' '.join(map(str, traversal))}\n{isComplete}", end="")


if __name__ == '__main__':
    summit()
