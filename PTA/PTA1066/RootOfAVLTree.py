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
        return self.label

    @property
    def value(self):
        """
        为了能够与格式化输出树的包相协调
        https://github.com/clemtoy/pptree
        :return: 返回节点的值
        """
        return self.label

    @property
    def children(self):
        """
        为了能够与格式化输出树的包相协调
        https://github.com/clemtoy/pptree
        :return: 返回节点的孩子
        """

        return [self.left if self.left is not None else [], self.right if self.right is not None else []]


def left_rotate(root: Node):
    """
    本函数给定根节点，对根节点进行左旋操作
    :param root: 最先不平衡的节点
    """
    # 保存一下「根节点的右子树的根节点」的「根节点」，防止第三步的时候找到不到「根节点的右子树的根节点」
    # 「根节点的右子树的根节点」将成为新的「根节点」
    rightOfRoot: Node = root.right
    # 「根节点的右子树的根节点」的左子树将依附到「根节点」的右子树上
    root.right = rightOfRoot.left
    # 将「根节点」依附到「根节点的右子树的根节点」的左子树上
    rightOfRoot.left = root
    # # 「根节点」指向的内存块变为「根节点的右子树的根节点」
    root = rightOfRoot


def summit():
    pass


if __name__ == '__main__':
    summit()
