from typing import List


# 链式存储结构
class Node:
    # 是否是mirror Image bst
    swap = False

    def __init__(self, label: int):
        self.label = label
        self.right = None
        self.left = None

    def __setattr__(self, key, value):
        if Node.swap:
            if key == "left":
                self.right = value
            else:
                self.left = value
        else:
            if key == "right":
                self.right = value
            else:
                self.left = value


def summit():
    # nodeNums = int(input())
    input()
    nums = list(map(int, input().split()))
    root = Node(nums[0])
    # 建树
    for num in nums[1:]:
        pass


if __name__ == '__main__':
    summit()
