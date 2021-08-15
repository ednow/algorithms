from typing import List, Dict, Union


# 二叉树的链式表示法
class Node:
    def __init__(self, index: int = None):
        self.index = index
        self.right = None
        self.left = None

    @property
    def value(self) -> str:
        return f"{self.index}"


# debug
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


def summit():
    nodesNum: int = int(input())
    nodes: List[Node] = [Node(i) for i in range(nodesNum)]
    # 记录每一个节点的father
    fathers: List[int] = [-1 for _ in range(nodesNum)]
    # 读取数据构建空树的连接情况
    for idx in range(nodesNum):
        strings = input().split()
        # 左子树有节点
        if strings[0] != "-":
            nodes[idx].left = nodes[int(strings[0])]
            fathers[int(strings[0])] = idx

        if strings[1] != "-":
            nodes[idx].right = nodes[int(strings[1])]
            fathers[int(strings[1])] = idx
    # 找到根节点
    root = 0
    while fathers[root] != -1:
        root = fathers[root]

    # 最后一个节点是啥
    last = 0
    # 层次遍历的结果
    result = []
    # 变种层次遍历，记录每一层的数量和最后一次输出该层元素时候的元素
    q: List[Union[None, Node]] = [nodes[root]]
    while len(q) > 0:
        if q[0] is not None:
            q.append(q[0].left)
            q.append(q[0].right)
            last = q[0].index
            result.append(q.pop(0).index)
        else:
            result.append(q.pop(0))

    # 层次遍历的结果中间不可能有空格
    resultStr = "".join(map(str, result)).replace("None", " ")

    if not (" " in resultStr.rstrip()):
        print(f"YES {last}")
    else:
        print(f"NO {root}")


if __name__ == '__main__':
    summit()
