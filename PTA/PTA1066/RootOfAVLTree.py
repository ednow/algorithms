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


def left_balance(root: Node):
    """
    就地对左边的子树进行平衡性调整
    :param root:
    """
    leftChildOfRoot: Node = root.left
    # LL调整
    if leftChildOfRoot.balanceFactor == 1:
        # 调整后平衡因子「根节点」和「根节点的左孩子」的平衡因子都为0
        root.balanceFactor = leftChildOfRoot.balanceFactor = 0
        right_rotate(root)
    # LR调整
    if leftChildOfRoot.balanceFactor == -1:
        # 「根节点的左孩子」的右子树
        rightChildOfLeftChild: Node = leftChildOfRoot.right
        # TODO:没来得及搞懂
        if rightChildOfLeftChild.balanceFactor == 1:
            root.balanceFactor = -1
            leftChildOfRoot.balanceFactor = 0

        if rightChildOfLeftChild.balanceFactor == 0:
            root.balanceFactor = leftChildOfRoot.balanceFactor = 0

        if rightChildOfLeftChild.balanceFactor == -1:
            root.balanceFactor = 0
            leftChildOfRoot.balanceFactor = 1

        #  调整root和leftChildOfRoot的平衡因子
        rightChildOfLeftChild.balanceFactor = 0
        left_rotate(leftChildOfRoot)
        right_rotate(root)


def insert_node(root: Node, label: int) -> bool:
    """
    给定根节点和关键字向二叉树中插入节点

    :return: 有没有长高,True长高了，False没有长高
    :param root: 根节点
    :param label: 待插入的关键字
    """
    if label < root.left:  # 比根节点小，插入到左边
        # 非空接着找左孩子，有没有位置可以插入
        if root.left is  None:
            root.left = Node(label)
            return True

        taller = insert_node(root.left, label)
        if taller:
            # 原本就是平衡的,被插入在了左边，自然平衡因子更新为1，且长高了
            if root.balanceFactor == 0:
                root.balanceFactor = 1
                return True

            # 原本右子树更高，被插入到了左边，平衡因子变为0
            if root.balanceFactor == -1:
                root.balanceFactor = 0
                return False

            # 本来左边就高，现在要插入到左边, 需要左旋
            if root.balanceFactor == 1:
                left_balance(root)
                return False

    else:
        # 非空接着找右孩子，有没有位置可以插入
        if root.right is not None:
            insert_node(root.right, label)

    return False


def summit():
    pass


if __name__ == '__main__':
    summit()
