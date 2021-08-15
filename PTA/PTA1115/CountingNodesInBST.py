from typing import List, Dict, Union


# 二叉树的链式表示法
class Node:
    def __init__(self, label: int = None):
        self.label = label
        self.right = None
        self.left = None

    @property
    def value(self) -> str:
        return f"{self.label}"

    def __gt__(self, other):
        return self.label >= other.label

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


def insert_node(root: Node, node: Node):
    """
    在二叉排序树中加入节点

    # copied from pta1043
    :param root: 二叉排序树的根节点
    :param node: 要插入到二叉排序树的节点
    """

    # 大的放在右边
    if node > root:
        if root.right is None:
            root.right = node
        else:
            insert_node(root.right, node)
    # 小的放左边
    else:
        if root.left is None:
            root.left = node
        else:
            insert_node(root.left, node)


def summit():
    nodesNum: int = int(input())
    if nodesNum == 1:
        print("1 + 0 = 1")
        return None
    nums: List[int] = list(map(int, input().split()))
    root = Node(nums[0])
    for num in nums[1:]:
        insert_node(root, Node(num))

    # copied from https://github.com/ednow/algorithms/commit/eaa68023f66ae9d22d492947a57018bfdcaef9a3
    # 每一层的信息{层数：节点数量}}
    nodeNumsByLevel: Dict[int, int] = dict()
    # 变种层次遍历，记录每一层的数量和最后一次输出该层元素时候的元素
    q: List[Dict[str, Union[int, Node]]] = [{"level": 1, "node": root}]
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
        q.pop(0)

    levelAndNums = sorted(nodeNumsByLevel.items(), key=lambda x: x[0])
    print(f"{levelAndNums[-1][1]} + {levelAndNums[-2][1]} = {levelAndNums[-1][1] + levelAndNums[-2][1]}")


if __name__ == '__main__':
    summit()
