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

    # reverse之后将后缀操作变成前缀操作
    link1.reverse()
    link2.reverse()
    for i in range(min(len(link1), len(link2))):
        if link1[i] == link2[i]:
            result = link1[i]

    print(result)


if __name__ == '__main__':
    summit()
