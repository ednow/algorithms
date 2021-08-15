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


def check_level(level: int, num: int) -> bool:
    """
    检查每一层的节点是否符合完全二叉树的定义
    :param level:
    :param num:
    :return:
    """
    return 2 ** (level - 1) == num


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

    # 每一层的信息{层数：{"nums": 节点数量，"last": 最后一个节点是啥}}
    # levelDetails: Dict[int, Dict[str, int]] = dict()
    # 每一层的信息{层数：{"nums": 节点数量，"last": 最后一个节点是啥}}
    nodeNumsByLevel: Dict[int, int] = dict()
    last = 0

    # 变种层次遍历，记录每一层的数量和最后一次输出该层元素时候的元素
    q: List[Dict[str, Union[int, Node]]] = [{"level": 1, "node": nodes[root]}]
    while len(q) > 0:
        if q[0]["node"].left is not None:
            q.append({
                "level": q[0]["level"] + 1,
                "node": q[0]["node"].left,
            })
        if q[0]["node"].right is not None:
            q.append({
                "level": q[0]["level"] + 1,
                "node": q[0]["node"].right,
            })
        nodeNumsByLevel[q[0]["level"]] = nodeNumsByLevel.get(q[0]["level"], 0) + 1
        last = q[0]["node"].index
        q.pop(0)

    # 检查每一层的节点数是否达标
    isOk = all(check_level(level, num) for level, num in sorted(nodeNumsByLevel.items(), key=lambda x: x[0])[:-1])
    if isOk:
        print(f"YES {last}")
    else:
        print(f"NO {root}")


if __name__ == '__main__':
    summit()
