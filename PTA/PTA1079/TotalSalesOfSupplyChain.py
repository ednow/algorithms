def summit():
    # members树中节点的个数,price原始单价,rate每一层价格提升的比例
    members, price, rate = map(float, input().split())
    rate /= 100  # rate是个百分数
    tree = [[] for _ in range(int(members))]
    # retailers,零售商卖货数
    retailers = dict()

    # 构建树
    for idx in range(int(members)):
        nums = list(map(int, input().split()))
        if nums[0] > 0:
            tree[idx].extend(nums[1:])
        else:
            # 记录这个零售商售卖了的数目
            retailers[idx] = nums[1]

    # 总的零售利润
    result = 0

    # 初始化遍历队列
    q = [{
        "level": 0,  # 所在的层号
        "label": 0  # 节点编号
        }]
    # 如果队列不为空
    while len(q) > 0:
        # 是叶子节点
        if len(tree[q[0]["label"]]) == 0:
            result += price * retailers[q[0]["label"]] * (1 + rate) ** q[0]["level"]
            # 弹出队首元素
            q.pop(0)
        else:
            for child in tree[q[0]["label"]]:
                q.append({
                    "level": q[0]["level"] + 1,  # 所在的层号
                    "label": child  # 节点编号
                })
            # 弹出队首元素
            q.pop(0)

    print(f"{result:.1f}")


if __name__ == '__main__':
    summit()
