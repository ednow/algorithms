from typing import List


class Node:
    def __init__(self, label: int = None):
        self.label = label
        self.right = None
        self.left = None


def insert_nodes(root: Node, preorderSeq: List[int], inorderSeq: List[int], isLeft: bool):
    """
    给定根节点和前序和中序序列找到下一个根节点，并递归建立二叉树
    :param root: 根节点父亲节点
    :param preorderSeq: 前序序列
    :param inorderSeq: 中序序列
    """
    # 递归终止
    # preorderSeq会有元素
    if len(preorderSeq) == 0 or len(inorderSeq) == 0:
        return None
    
    child = Node(preorderSeq[0])
    if isLeft:
        root.left = child
    else:
        root.right = child

    # 通过中序序列找到前序序列左子树的部分
    maxLeftIndexOfPreorder = -1
    for idx in range(len(preorderSeq)):
        if preorderSeq[idx] in inorderSeq[:inorderSeq.index(child.label)]:
            maxLeftIndexOfPreorder = idx

    insert_nodes(child, preorderSeq[1:maxLeftIndexOfPreorder + 1], inorderSeq[:inorderSeq.index(child.label)], True)
    insert_nodes(child, preorderSeq[maxLeftIndexOfPreorder + 1:], inorderSeq[inorderSeq.index(child.label) + 1:], False)


def post_order(root: Node, result: List[int]):
    """
    给定二叉树的根节点进行递归后序遍历
    :param root: 根节点
    :param result: 遍历存放的节点顺序的位置
    """
    if root is None:
        return None
    post_order(root.left, result)
    post_order(root.right, result)
    result.append(root.label)


def summit():
    # 操作的步数
    operationsNum = int(input()) * 2
    # 先序遍历的序列
    preorderSeq: List[int] = []
    # 后序遍历的序列
    postorderSeq: List[int] = []
    # 中序遍历的序列
    inorderSeq: List[int] = []
    # 栈
    stack: List[int] = []

    # 建立后序序列和中序遍历序列
    for _ in range(operationsNum):
        strings: List[str] = input().split()
        # pop操作
        if len(strings) == 1:
            inorderSeq.append(stack.pop(-1))
            continue

        # push操作
        num = int(strings[1])
        stack.append(num)
        preorderSeq.append(num)

    # 只有一个节点
    if len(preorderSeq) == 1:
        print(preorderSeq[0])
        return None

    root = Node(preorderSeq[0])
    # 通过中序序列找到前序序列左子树的部分
    maxLeftIndexOfPreorder = -1
    for idx in range(len(preorderSeq)):
        if preorderSeq[idx] in inorderSeq[:inorderSeq.index(root.label)]:
            maxLeftIndexOfPreorder = idx

    insert_nodes(root, preorderSeq[1:maxLeftIndexOfPreorder + 1], inorderSeq[:inorderSeq.index(root.label)], True)
    insert_nodes(root, preorderSeq[maxLeftIndexOfPreorder + 1:], inorderSeq[inorderSeq.index(root.label) + 1:], False)
    result = []
    post_order(root, result)
    print(" ".join(map(str, result)))


if __name__ == '__main__':
    summit()
