from typing import List, Dict


def summit():
    nodesNum, notLeafNodesNum = map(int, input().split())
    # 孩子兄弟表示法
    tree = [[] for _ in range(nodesNum + 1)]
    # 建树
    for _ in range(notLeafNodesNum):
        nums = list(map(int, input().split()))
        tree[nums[0]].extend(nums[2:])
    # 对应层的节点数
    nodesByLevel: Dict[int, int] = dict()
    # 队列
    q: List[Dict[str, int]] = [{"label": 1, "level": 1}]
    while len(q) > 0:
        # 孩子入队
        for label in tree[q[0]["label"]]:
            q.append(
                {
                    "label": label,
                    "level": q[0]["level"] + 1
                }
            )

        nodesByLevel[q[0]["level"]] = nodesByLevel.get(q[0]["level"], 0) + 1

        q.pop(0)

    maxGeneration = max(nodesByLevel.items(), key=lambda x: x[1])

    print(f"{maxGeneration[1]} {maxGeneration[0]}")


if __name__ == '__main__':
    summit()
