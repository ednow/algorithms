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
# OJ环境没有这个包
try:
    from ppbtree import print_tree
except Exception as e:
    pass

from typing import List


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
        为了能够与格式化输出**二叉树**的包相协调
        https://github.com/clemtoy/pptree
        :return: 返回节点的值
        """
        return f"label:{self.label},bf:{self.balanceFactor}"

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

    写成这样就是因为python中没有二级指针,赋值顺序满足拓扑排序(不然会影响真正值的连接

    这个和balance_left不一样，balance_left是平衡左子树，中的left是指子树;
    这里的left是指将root向左旋转
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

    写成这样就是因为python中没有二级指针,赋值顺序满足拓扑排序(不然会影响真正值的连接
    :param root: 最先不平衡的节点
    """
    b: Node = root.left
    root.left = b.left
    b.left = b.right
    b.right = root.right
    root.right = b
    root.label, b.label = b.label, root.label


def balance_left(root: Node):
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
        # 「「根节点的左孩子」的右子树」
        rightChildOfLeftChild: Node = leftChildOfRoot.right
        # 新插入的节点位于「「根节点的左孩子」的右子树」的左子树上
        if rightChildOfLeftChild.balanceFactor == 1:
            root.balanceFactor = -1
            leftChildOfRoot.balanceFactor = 0

        # 新插入的节点就是「「根节点的左孩子」的右子树」
        if rightChildOfLeftChild.balanceFactor == 0:
            root.balanceFactor = leftChildOfRoot.balanceFactor = 0

        # 新插入的节点位于「「根节点的左孩子」的右子树」的右子树上
        if rightChildOfLeftChild.balanceFactor == -1:
            root.balanceFactor = 0
            leftChildOfRoot.balanceFactor = 1

        #  调整root和leftChildOfRoot的平衡因子
        rightChildOfLeftChild.balanceFactor = 0
        left_rotate(leftChildOfRoot)
        right_rotate(root)


def balance_right(root: Node):
    """
    根节点对右边的子树进行平衡性调整
    :param root: 最早出现失衡问题的节点
    """
    rightChildOfRoot: Node = root.right

    # 右边原本更高，现在又插入了右边
    if rightChildOfRoot.balanceFactor == -1:
        # 见书中的图
        root.balanceFactor = rightChildOfRoot.balanceFactor = 0
        left_rotate(root)

    # 需要进行两次旋转
    if rightChildOfRoot.balanceFactor == 1:
        leftChildOfRightChild: Node = rightChildOfRoot.left

        """// 调整 root 和 rightChildOfRoot 的平衡因子"""
        # 如果插入的节点就是leftChildOfRightChild
        if leftChildOfRightChild.balanceFactor == 0:
            root.balanceFactor = rightChildOfRoot.balanceFactor = 0

        # 课本中描述的情况,插入到了leftChildOfRightChild的左子树上
        if leftChildOfRightChild.balanceFactor == 1:
            root.balanceFactor = 0
            rightChildOfRoot.balanceFactor = -1

        # 课本中没有画图的情况,插入到了leftChildOfRightChild的右子树上
        if leftChildOfRightChild.balanceFactor == -1:
            root.balanceFactor = 1
            rightChildOfRoot.balanceFactor = 0
            pass
        """调整 root 和 rightChildOfRoot 的平衡因子 //"""

        # 调整完毕之后，成为根节点的节点平衡因子必定是0
        leftChildOfRightChild.balanceFactor = 0

        # 先右选
        right_rotate(rightChildOfRoot)
        # 再左旋
        left_rotate(root)


def insert_node(root: Node, label: int) -> bool:
    """
    给定根节点和关键字向二叉树中插入节点

    :return: 有没有长高,True长高了，False没有长高
    :param root: 根节点
    :param label: 待插入的关键字
    """
    # 这里是label的比别乱搞
    if label < root.label:  # 比根节点小，插入到左边
        # 非空接着找左孩子，有没有位置可以插入
        if root.left is None:
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
                balance_left(root)
                return False

    else:
        # 非空接着找右孩子，有没有位置可以插入
        if root.right is None:
            root.right = Node(label)

        taller = insert_node(root.right, label)
        if taller:
            # 原本就是平衡的,被插入在了右边，自然平衡因子更新为-1，且长高了
            if root.balanceFactor == 0:
                root.balanceFactor = -1
                return True

            # 原本左边更高，现在插入到了右边，自然平衡因子变为0，且每“长高”
            if root.balanceFactor == 1:
                root.balanceFactor = 0
                return False

            # 原本右边就高，现在插入到了右边，需要右选
            if root.balanceFactor == -1:
                balance_right(root)

    return False


def summit():
    input()
    nums: List[int] = list(map(int, input().split()))
    root = Node(nums[0])
    globals()["ROOT"] = root  # debug
    for num in nums[1:]:
        insert_node(root, num)
    # print(root.label)


if __name__ == '__main__':
    summit()
