"""
本代码参考严蔚敏<数据结构(c语言版)>中教材的思路
(pp.247-250, pr.235-238,即实体书的第235至238页)

涉及到平衡二叉树的插入算法

平衡二叉树的插入算法的重点在于
+ 平衡调整（）
+ 节点平衡度的更新（插入之后更新节点平衡度的值）

Q: 如何理解右旋
A: 把最小不平衡子树的根节点变为其左孩子的右孩子,将左孩子的右子树化到其左子树中,可以立即为swap(根节点，根节点的左孩子)。同理左旋。

Q: 左右双旋和右旋中的直觉?
A: 「从哪条路来的回哪条路去」

Q: 如何让程序看见此时的旋转状态?
A: 表示节点的数据中增加的一个

"""
from ppbtree import print_tree


# 平衡二叉树的节点
class Node:
    def __init__(self, label: int = None):
        self.label = label
        self.left = None
        self.right = None
        # balanceFactor(平衡因子)
        # 当平衡因子为0的时候，左右子树等高
        # 当平衡因子为1的时候，左子树比右子树高
        # 当平衡因子为-1的时候，右子树比左子树高
        self.balanceFactor = 0

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
        为了能够与格式化输出树的包相协调
        https://github.com/clemtoy/pptree
        :return: 返回节点的值
        """
        return str(self.label)

    @property
    def children(self):
        """
        为了能够与格式化输出树的包相协调
        https://github.com/clemtoy/pptree
        :return: 返回节点的孩子
        """
        return filter(lambda x: x is not None, [self.left, self.right])


def left_rotate(root: Node):
    """
    本函数给定根节点，对根节点进行就地左旋操作

    写成这样就是因为python中没有二级指针,赋值顺序满足拓扑排序(待证明，直觉告诉我要这样操作
    :param root: 最先不平衡的节点
    """
    b: Node = root.right
    root.right = b.right
    b.right = b.left
    b.left = root.left
    root.left = b
    root.label, b.label = b.label, root.label


def right_rotate(root: Node):
    """
    本函数给定根节点，对根节点进行就地右旋操作

    写成这样就是因为python中没有二级指针,赋值顺序满足拓扑排序(待证明，直觉告诉我要这样操作
    :param root: 最先不平衡的节点
    """
    b: Node = root.left
    root.left = b.left
    b.left = b.right
    b.right = root.right
    root.right = b
    root.label, b.label = b.label, root.label


def summit():
    pass


if __name__ == '__main__':
    summit()
