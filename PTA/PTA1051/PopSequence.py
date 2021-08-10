from typing import List, Union


class Stack:
    # s: List[int] 栈的内容,
    # remain: int 栈中的剩余容量
    __slots__ = 's', 'remain'


def summit():
    # stackSize栈的长度, num一共需要压栈的元素的数量, checkNum一共需要校验的序列的数量
    stackSize, num, checkNum = map(int, input().split())
    # 需要校验的序列
    seqs: List[List[Union[int, float]]] = []
    # 读入需要比对的列表们
    for _ in range(checkNum):
        seqs.append(list(map(int, input().split())))

    result = ""
    for seq in seqs:
        s = Stack()
        s.s = []
        s.remain = stackSize
        # 原始列表的元素
        L = [i for i in range(1, num + 1)]
        # 是否是一个正确的弹出序列
        isOK = True

        # 工作指针从1开始移动
        for idx in range(0, num):
            # 由于上一次操作弹出了元素，或者没有元素,需要压入元素
            if len(s.s) == 0:
                s.s.append(L.pop(0))
                s.remain -= 1

            # 如果栈顶的元素不是现在工作指针指向的元素,而且列表中还有元素可以压进去,将列表中的元素压入栈中
            while s.remain > 0 and s.s[-1] != seq[idx] and len(L) > 0:
                s.s.append(L.pop(0))
                s.remain -= 1

            # 如果栈顶的元素是现在指针指向的元素，弹出列表中的元素，指针后移
            if s.s[-1] == seq[idx]:
                s.s.pop(-1)
                s.remain += 1
                continue

            # 栈都已经满了还无法弹出或者L被全部压入栈，但是工作指针没有结束,证明无法完成这样的弹出序列
            if s.remain == 0 or len(L) == 0:
                result += "NO\n"
                isOK = False
                break
        if isOK:
            result += "YES\n"

    print(result, end="")


if __name__ == '__main__':
    summit()
