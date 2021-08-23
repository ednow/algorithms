from typing import List


class Node:
    def __init__(self, index: int):
        self.index = index
        self.father = -1
        self.data = None
        self.left = None
        self.right = None

    @property
    def has_children(self):
        if self.left is None and self.right is None:
            return False
        else:
            return True


def inorder_traversal(root: Node, result: List[str]):
    if root is None:
        return None
    if root.has_children:
        result.append("(")
        inorder_traversal(root.left, result)
        result.append(root.data)
        inorder_traversal(root.right, result)
        result.append(")")
    else:
        result.append(root.data)


def summit():
    nodeNum: int = int(input())
    nodes: List[Node] = [Node(idx) for idx in range(0, nodeNum+1)]
    for idx in range(1, nodeNum+1):
        strings = input().split()
        # 左孩子不为空
        if strings[1] != "-1":
            nodes[idx].left = nodes[int(strings[1])]
            nodes[idx].left.father = nodes[idx]
        # 右孩子不为空
        if strings[2] != "-1":
            nodes[idx].right = nodes[int(strings[2])]
            nodes[idx].right.father = nodes[idx]

        nodes[idx].data = strings[0]

    root = nodes[1]
    while root.father != -1:
        root = root.father

    result = []
    inorder_traversal(root, result)
    print("".join(result[1:-1]))


if __name__ == '__main__':
    summit()
