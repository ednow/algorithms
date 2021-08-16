from typing import List
import sys
# 设置最大递归数
sys.setrecursionlimit(3000)


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

    def __gt__(self, other):
        return self.label > other.label

    def __ge__(self, other):
        return self.label >= other.label

    def __lt__(self, other):
        return self.label < other.label

    def __le__(self, other):
        return self.label <= other.label


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


def postorder_traversal(root: Node, result: List[int]):
    """
    后序遍历二叉树
    :param root: 二叉树的根节点
    :param result: 后序序列存放的列表
    :return:
    """
    if root is None:
        return None

    postorder_traversal(root.left, result)
    postorder_traversal(root.right, result)
    result.append(root.label)


def judge_one_case(nodesNum: int) -> str:
    """
    返回f"{堆的类型}\n{中序遍历的结果}"
    :param nodesNum: 节点的数量
    """
    nodes: List[Node] = [Node(num) for num in map(int, input().split())]
    # bug:因为从0开始算下标，所以越界的下标需要-1
    nodesNum -= 1
    # 第一个大于第二个元素，有可能是大顶堆
    if nodes[0] > nodes[1]:
        isMayMaxHeap = True
    else:
        isMayMaxHeap = False

    # 是不是堆
    isHeap = True
    # 检查到底是不是满足堆的定义，并且根据二叉树的链式存储结构建立二叉树
    for idx in range(int(nodesNum/2) + 1):  # bug:range是右开区间
        # 左孩子的下标
        leftIdx = idx * 2 + 1   # 注意要加1
        # 右孩子的下标
        rightIdx = idx * 2 + 2
        # 有可能是大顶堆
        if isMayMaxHeap:
            if leftIdx <= nodesNum:
                # 既然之前觉得是大顶堆就检查一下，现在这个符不符合，如果不符合,就设为False
                if isHeap:
                    if nodes[idx] < nodes[leftIdx]:  # 看一下左孩子满不满足大顶堆的定义
                        isHeap = False
                # 插入左孩子
                nodes[idx].left = nodes[leftIdx]
            if rightIdx <= nodesNum:
                # 既然之前觉得是大顶堆就检查一下，现在这个符不符合，如果不符合,就设为False
                if isHeap:
                    if nodes[idx] < nodes[rightIdx]:  # 看一下左孩子满不满足大顶堆的定义
                        isHeap = False
                # 插入右孩子
                nodes[idx].right = nodes[rightIdx]
        else:  # 有可能是小顶堆
            if leftIdx <= nodesNum:
                # 既然之前觉得是小顶堆就检查一下，现在这个符不符合，如果不符合,就设为False
                if isHeap:
                    if nodes[idx] >= nodes[leftIdx]:  # 看一下左孩子满不满足大顶堆的定义
                        isHeap = False
                # 插入左孩子
                nodes[idx].left = nodes[leftIdx]
            if rightIdx <= nodesNum:
                # 既然之前觉得是小顶堆就检查一下，现在这个符不符合，如果不符合,就设为False
                if isHeap:
                    if nodes[idx] >= nodes[rightIdx]:  # 看一下左孩子满不满足大顶堆的定义
                        isHeap = False
                # 插入右孩子
                nodes[idx].right = nodes[rightIdx]

    if isHeap:
        if isMayMaxHeap:
            isWhatHeap = "Max"
        else:
            isWhatHeap = "Min"
    else:
        isWhatHeap = "Not"

    result = []
    postorder_traversal(nodes[0], result)
    return f"{isWhatHeap} Heap\n{' '.join(map(str, result))}"


def summit():
    caseNum, nodesNum = map(int, input().split())
    print("\n".join(judge_one_case(nodesNum) for _ in range(caseNum)))


if __name__ == '__main__':
    summit()
