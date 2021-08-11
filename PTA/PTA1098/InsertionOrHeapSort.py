from typing import List
from math import floor

def Insertion_adjust(seq: List[int], lastWorkPointer: int):
    """
    进行下一轮的直接插入排序
    :param seq: 需要操作的序列
    :param lastWorkPointer: 上一次工作指针的位置
    """
    # 应该操作下一个元素了
    workPointer = lastWorkPointer + 1
    # 待插入元素的值
    val = seq[workPointer]
    # 从后往前查找插入位置
    for idx in range(workPointer - 1, -1, -1):
        if seq[idx] < val:  # 找到插入位置
            seq[idx + 1] = val
            break
        else:  # 元素后移
            seq[idx + 1] = seq[idx]


def Heap_adjust(seq: List[int], lastWorkPointer: int):
    """
    进行下一轮堆排序
    :param seq: 需要操作的序列
    :param lastWorkPointer: 上一次工作指针的位置
    """
    # 现在要操作的元素
    workPointer = lastWorkPointer - 1
    # 输出堆顶元素
    seq[workPointer], seq[0] = seq[0], seq[workPointer]
    # 将此时的堆顶元素向下调整
    pointer = 0
    while pointer < workPointer - 1:  # 没有超过堆的范围
        nextPointer = pointer * 2  # 下一层的工作指针
        # 从 [根节点，左孩子，右孩子] 找出当前最大的节点
        maxNode = max(
            [pointer, seq[pointer]], [nextPointer, seq[nextPointer + 1]], [nextPointer, seq[nextPointer + 2]],
            key=lambda x: x[1]
        )

        # 根节点就是最大的，不用向下调整
        if maxNode[0] == pointer:
            break

        # 向下调整
        seq[pointer], seq[maxNode[0]] = seq[maxNode[0]], seq[pointer]

        # 更新工作指针
        pointer = maxNode[0]


def summit():
    input()
    # 初始序列
    rawSeq = list(map(int, input().split()))
    # 当前的序列
    currentSeq = list(map(int, input().split()))
    # 使用的方法
    fun = ''
    # 如果左边被排好了就是直接插入排序，右边被排好了就是堆排序
    isSorted = [a == b for a, b in zip(sorted(rawSeq), currentSeq)]
    # 现在最近哪个元素被移到了正确的位置上
    workPointer = isSorted.index(True)

    if all(isSorted[:workPointer]):  # 左边都被排好?
        fun = 'Insertion'  # 左边都被排好,采用的排序算法是插入排序
    else:
        fun = 'Heap'  # 右边都被排好,采用的排序算法是堆排序

    # 进行下一轮排序
    globals()[f"{fun}_adjust"](currentSeq, workPointer)

    print(f"{fun} Sort\n{' '.join(map(str, currentSeq))}")


if __name__ == '__main__':
    summit()
