from typing import List, Union


class Stack:
    # s存放元素,remain是否还有
    __slots__ = 's', 'remain'


def summit():
    # stackSize栈的长度, num一共需要压栈的元素的数量, checkNum一共需要校验的序列的数量
    stackSize, num, checkNum = map(int, input().split())
    # 需要校验的序列
    seqs: List[List[Union[int, float]]] = []
    for _ in range(checkNum):
        seqs.append(list(map(int, input().split())))

    correctSeq = [i for i in range(1, num+1)]
    result = ""
    for seq in seqs:
        s = Stack()
        s.s = []
        s.remain = stackSize

        # output跟correctSeq一致就是能够通过
        output = []
        # 必须保证每一个要check的序列都是长度和序列长度一致
        seq.append(float('inf'))
        # 第一个元素压入栈中

        for idx in range(0, num):
            # 将元素压入栈中
            if s.remain > 0:
                s.s.append(seq[idx])
                s.remain -= 1

            if seq[idx] < seq[idx+1]:
                while len(s.s) > 0:
                    # 将元素压入队列
                    output.append(s.s.pop(-1))
                    s.remain += 1

        if correctSeq == output:
            result += "Yes\n"
        else:
            result += "No\n"

    print(result, end="")


if __name__ == '__main__':
    summit()
