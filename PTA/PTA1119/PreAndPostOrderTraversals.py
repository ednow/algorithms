from typing import List


class Node:
    def __init__(self, idx: int = None):
        self.label = idx
        self.children = []
        self.left = None
        self.right = None

    @property
    def name(self):
        return str(self.label)

    @property
    def value(self):
        return str(self.label)


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


def get_degrees(root: Node) -> List[int]:
    """
    返回一棵树的出度们
    :param root: 树
    """
    if root is None:
        return []

    return sum((get_degrees(child) for child in root.children), []) + [len(root.children)]


def attach_node(root: Node, seq: List[int]):
    """
    给定一棵树递归的依附节点到树上

    操作原理：定理2

    如果不能确定孩子是左子树还是右子树那么孩子将被挂在左子树上
    :param seq: 前序，中序，后序遍历序列中的任何一个
    :param root: 需要依附孩子节点的根节点
    """
    # 没有孩子需要连接或者当前的节点是None那么结束递归
    if root is None or len(root.children) == 0:
        return None

    if len(root.children) == 1:
        root.left = root.children[0]
        attach_node(root.left, seq)
        return None

    # 节点有两个孩子
    # 第一个元素在前面，那么他是左孩子，反之他是右孩子
    if seq.index(root.children[0].label) < seq.index(root.children[1].label):
        root.left = root.children[0]
        root.right = root.children[1]
        attach_node(root.left, seq)
        attach_node(root.right, seq)
    else:
        root.left = root.children[1]
        root.right = root.children[0]
        attach_node(root.left, seq)
        attach_node(root.right, seq)


def inorder_traversal(root: Node, result: List[int]):
    """
     给定一颗二叉树中序遍历之
    :param root: 树
    :param result: 存放结果
    """
    if root is None:
        return None

    inorder_traversal(root.left, result)
    result.append(root.label)
    inorder_traversal(root.right, result)


def summit():
    nodesNum: int = int(input())
    preOrderSeq: List[int] = list(map(int, input().split()))
    postOrderSeq: List[int] = list(map(int, input().split()))
    if nodesNum == 1:
        print(f"Yes\n{preOrderSeq[0]}")
        return None
    nodes: List[Node] = [Node(i) for i in range(0, max(preOrderSeq) + 1)]

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

    degrees = get_degrees(nodes[preOrderSeq[0]])

    isUnique = "No"
    # 根据定理3判断是否唯一
    # 有出度为1的节点
    if 1 in degrees:
        isUnique = "No"
    else:
        isUnique = "Yes"

    # 根据定理2确定节点每一颗节点的孩子们是左是右
    attach_node(nodes[preOrderSeq[0]], preOrderSeq)

    # 存放中序遍历的序列
    result = []

    inorder_traversal(nodes[preOrderSeq[0]], result)

    # 输出
    print(f"{isUnique}\n{' '.join(map(str, result))}")


if __name__ == '__main__':
    summit()
