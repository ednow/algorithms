from __future__ import annotations
from typing import List
# OJ环境没有这个包
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

    def __str__(self):
        return str(self.label)

    @property
    def name(self):
        """
        为了能够与格式化输出树的包相协调
        https://github.com/clemtoy/pptree
        :return: 返回节点的值
        """
        return str(self.label)

    @property
    def value(self):
        """
        为了能够与格式化输出**二叉树**的包相协调
        https://github.com/clemtoy/pptree
        :return: 返回节点的值
        """
        return f"label:{self.label},bf:{self.bf}"


def right_rotate(root: Node):
    """
    向右旋转

    新节点插入到了左子树的左子树上只会调用这个方法
    :param root: 需要旋转的节点
    """
    leftOfRoot: Node = root.left
    root.left = leftOfRoot.left
    leftOfRoot.left = leftOfRoot.right
    leftOfRoot.right = root.right
    root.right = leftOfRoot
    leftOfRoot.label, root.label = root.label, leftOfRoot.label
    root.bf, leftOfRoot.bf = leftOfRoot.bf, root.bf


def left_rotate(root: Node):
    """
    向左旋转

    新节点插入到了右子树的右子树上只会调用这个方法
    :param root: 需要旋转的节点
    """
    rightOfRoot: Node = root.right
    root.right = rightOfRoot.right
    rightOfRoot.right = rightOfRoot.left
    rightOfRoot.left = root.left
    root.left = rightOfRoot
    rightOfRoot.label, root.label = root.label, rightOfRoot.label
    rightOfRoot.bf, root.bf = root.bf, rightOfRoot.bf


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

    left_rotate(leftOfRoot)
    right_rotate(root)


def right_balance(root: Node):
    """

    :param root:
    :return:
    """
    rightOfRoot: Node = root.right
    if rightOfRoot.bf == -1:
        left_rotate(root)
        rightOfRoot.bf = root.bf = 0
        return None
    leftOfRight: Node = rightOfRoot.left

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

    right_rotate(rightOfRoot)
    left_rotate(root)


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
    # globals()["ROOT"] = root  # debug
    for num in nums[1:]:
        insert_node(root, Node(num))

    q = [root]
    traversal: List[int] = []
    while len(q) > 0:
        head = q.pop(0)
        traversal.append(head)
        if head is not None:
            q.append(head.left)
        if head is not None:
            q.append(head.right)
    if " " in "".join(map(str, traversal)).replace("None", " ").strip():
        isComplete = "NO"
    else:
        isComplete = "YES"

    print(f'{" ".join(map(str, filter(lambda x: x is not None, traversal)))}\n{isComplete}', end="")


if __name__ == '__main__':
    summit()
