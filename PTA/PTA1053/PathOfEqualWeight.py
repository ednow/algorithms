from functools import reduce


def summit():
    # nodesNum树中总的节点数, notLeafNodeNum非叶子节点数,weight需要求的权值数
    nodesNum, notLeafNodeNum, weight = map(int, input().split())
    # weights：每个节点的权值
    weights = list(map(int, input().split()))
    #  树的结构采用孩子兄弟表示法
    tree = [[] for _ in range(nodesNum)]
    # 所有节点都是叶子节点
    isLeaf = [True for _ in range(nodesNum)]
    # 读入层次关系
    for _ in range(notLeafNodeNum):
        nums = list(map(int, input().split()))
        tree[nums[0]].extend(nums[2:])
        isLeaf[nums[0]] = False

    # 满足要求的路径
    result = []
    # 初始化工作栈中的元素
    stack = [0]
    if len(tree[0]) > 0:
        stack.append(tree[0].pop(0))
    else:
        if weights[0] == weight:
            print(weights[0])
        else:
            print("")
        return None
    # 工作栈顶的元素不是根节点
    while stack[-1] != 0:
        currentWeight = reduce(lambda a, b: a + weights[b], stack, 0)
        # 如果现在的路径的带权长度就是目标长度
        if currentWeight == weight and isLeaf[stack[-1]]:
            result.append([weights[i] for i in stack])
            stack.pop(-1)
            continue

        if currentWeight == weight and not isLeaf[stack[-1]]:
            stack.pop(-1)
            continue

        # 如果现在的路径的带权路径长度大于目标长度
        # 这个节点不需要再考虑,压入父亲节点的下一个节点
        if currentWeight > weight:
            stack.pop(-1)
            if len(tree[stack[-1]]) > 0:
                stack.append(tree[stack[-1]].pop(0))
            continue

        # 如果现在这个节点的带权路径长度小于目标长度
        # 如果有孩子，压入孩子，
        # 否则这个节点被弹出,压入父亲节点的孩子节点
        if len(tree[stack[-1]]) > 0:
            stack.append(tree[stack[-1]].pop(0))
        else:
            stack.pop(-1)
            if len(tree[stack[-1]]) > 0:
                stack.append(tree[stack[-1]].pop(0))

    # 按照题目的要求对节点排序
    maxLen = len(max(result, key=lambda x: len(x)))  # 最大的结果的路径长度
    result.sort(
        key=lambda x: [x[i] if i < len(x) else 0 for i in range(maxLen)],
        reverse=True
    )

    print("\n".join([" ".join(map(str, i)) for i in result]))


if __name__ == '__main__':
    summit()
