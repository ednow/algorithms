from typing import Dict
from math import ceil

def summit():
    N, G = map(int, input().split())
    # 每一名老鼠的重量
    weights: Dict[int, int] = {
        k: v for k, v in enumerate(map(int, input().split()))
    }
    # nextOrders下一次比赛的顺序，
    nextOrders = list(map(int, input().split()))
    # 进入比赛的选手们
    compete = []
    # 这一次比赛的顺序
    orders = []
    # 选手排名,k:选手编号，v:选手排名
    ranks: Dict[int, int] = dict()
    # rank会随着比赛的进行--,为了得到真正的排名需要加上场数
    rank = 0
    while len(nextOrders) > 0:
        orders = nextOrders
        group = ceil(len(orders) / G)

        # 只有一个就不比了
        if len(orders) == 1:
            ranks[orders[0]] = 1
            break

        nextOrders = []
        # 这一场还没有比完
        while len(orders) > 0:
            winner = max(orders[:G], key=lambda x: weights[x])
            # 赢的人进入下一场
            nextOrders.append(winner)
            # 输的人被淘汰
            for one in orders[:G]:
                if one != winner:
                    ranks[one] = group + 1
            orders = orders[G:]

    result = []
    # 修正排名
    for i in range(N):
        result.append(str(ranks[i]))

    print(" ".join(result))


if __name__ == '__main__':
    summit()
