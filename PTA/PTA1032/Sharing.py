from typing import List, Dict


def summit():
    head1, head2, nodeNum = input().split()
    link1: List[str] = []
    link2: List[str] = []
    memory: Dict[str, str] = {}
    result = "-1"

    # 生成内存块
    for _ in range(int(nodeNum)):
        address, _, pointer = input().split()
        memory[address] = pointer

    # 生成两个链表
    for link, head in zip([link1, link2], [head1, head2]):
        link.append(head)
        while head != "-1":
            link.append(memory[head])
            head = memory[head]

    # 对齐再比较
    link1Len = len(link1)
    link2Len = len(link2)
    if link1Len > link2Len:
        link1 = link1[-link2Len:]
        end = link2Len
    else:
        link2 = link2[-link1Len:]
        end = link1Len

    for i in range(end):
        if link1[i] == link2[i]:
            result = link1[i]
            break

    print(result)


if __name__ == '__main__':
    summit()
