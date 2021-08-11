from typing import List
from math import floor


def insertion_adjust(currentSeq: List[int], rawSeq: List[int]):
    """
    进行下一轮的直接插入排序
    :param currentSeq: 需要操作的序列
    :param rawSeq: 该操作序列的原始序列
    """
    # 找到下一个需要插入的元素
    workPointer = 0
    for idx in range(len(rawSeq) - 1, 0, -1):
        if not all([a == b for a, b in zip(sorted(rawSeq[:idx]), currentSeq[:idx])]):
            continue
        workPointer = idx
        break

    # 待插入元素的值
    val = currentSeq[workPointer]
    pos = 0
    # 从后往前查找插入位置
    for idx in range(workPointer - 1, -1, -1):
        if currentSeq[idx] < val:  # 找到插入位置
            pos = idx + 1
            break
        else:  # 元素后移
            currentSeq[idx + 1] = currentSeq[idx]

    # 插入位置是0的话要收尾
    currentSeq[pos] = val


def heap_adjust(seq: List[int], lastWorkPointer: int):
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
    while pointer < floor(workPointer/2):  # 没有超过堆的范围
        nextPointer = pointer * 2  # 下一层的工作指针

        # 需要比较的节点
        compares = [[pointer, seq[pointer]], [nextPointer + 1, seq[nextPointer + 1]]]

        # 如果有右孩子,且不是输出的堆顶元素
        if nextPointer + 2 < workPointer - 1:
            compares.append([nextPointer + 2, seq[nextPointer + 2]])

        # 从 [根节点，左孩子，右孩子] 找出当前最大的节点
        maxNode = max(compares, key=lambda x: x[1])

        # 根节点就是最大的，不用向下调整 or 防止左孩子是被输出的堆顶的元素
        if maxNode[0] == pointer or maxNode[0] == workPointer:
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
    # 现在最近哪个元素被移到了正确的位置上,测试点2：由于插入排序所以都是False的情况
    workPointer = isSorted.index(True) if True in isSorted else 0

    if all(isSorted[workPointer:]):  # 右边都被排好?
        fun = 'Heap'  # 右边都被排好,采用的排序算法是堆排序
        heap_adjust(currentSeq, workPointer)
    else:
        fun = 'Insertion'  # 否则是插入排序
        insertion_adjust(currentSeq, rawSeq)

    print(f"{fun} Sort\n{' '.join(map(str, currentSeq))}")


if __name__ == '__main__':
    summit()
