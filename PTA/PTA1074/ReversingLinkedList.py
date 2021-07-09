from typing import List, Dict


def summit():
    head, nodeNum, step = input().split()
    memory: Dict[str, str] = {}
    link1: List[str] = []

    # 生成内存块
    for _ in range(int(nodeNum)):
        address, _, pointer = input().split()
        memory[address] = pointer


if __name__ == '__main__':
    summit()
