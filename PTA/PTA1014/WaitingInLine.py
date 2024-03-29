from typing import List, Dict
from math import floor


class Customer:
    """
    id: int 客户id
    remain: int 剩余的时间戳
    """
    __slots__ = 'id', 'remain'


class Queue:
    """
    q: List[Customer] 队列，这个窗口黄线前的客户
    remain: int 这个窗口黄线前剩余容量
    """
    __slots__ = 'q', 'remain'


def summit():
    # N窗户的数量，M每一个窗户的最大容量，K今天的客流量，Q询问处理时间的客户
    N, M, K, Q = map(int, input().split())
    # queue中的元素为Customer
    windows: List[Queue] = []
    # 初始化银行窗口
    for _ in range(N):
        q = Queue()
        q.q = []
        q.remain = M
        windows.append(q)

    # 已完成的客户们
    finishDict: Dict[int, str] = dict()
    # 正在等待的客户们
    waitingList: List[Customer] = []

    # 读入客源信息,存放到等待队列
    for idx, remain in enumerate(map(int, input().split())):
        c = Customer()
        c.id = idx + 1
        c.remain = remain
        waitingList.append(c)

    # 读入查询请求
    queries = list(map(int, input().split()))

    # 模拟排队
    time = 0  # 时间戳置0
    # 初始化窗口
    # 如果黄线前还有位置，那么客户站进去
    while any([q.remain > 0 for q in windows]) and len(waitingList) != 0:
        # 选一条等的人数最少的窗口
        window = max(windows, key=lambda x: x.remain)
        # 让等待的人进黄线内等
        window.q.append(waitingList.pop(0))
        # 窗口的容量更新
        window.remain -= 1

    # 如果还有客户没有得到处理，而且银行没有下班,窗口中还有人等待处理
    while any([len(q.q) > 0 for q in windows]):
        # 如果黄线前还有位置，那么客户站进去,银行下班进不了黄线
        while any([q.remain > 0 for q in windows]) and len(waitingList) != 0 and time < 6 * 90:
            # 选一条等的人数最少的窗口
            window = max(windows, key=lambda x: x.remain)
            # 让等待的人进黄线内等
            window.q.append(waitingList.pop(0))
            # 窗口的容量更新
            window.remain -= 1

        # 这个窗口被标记为结束
        finishWindow = min(windows, key=lambda x: x.q[0].remain if len(x.q) > 0 else float("inf"))
        timePass = finishWindow.q[0].remain

        # 更新总的时间戳
        time += timePass
        # 对所有窗口正在处理的人更新剩余时间戳
        for window in windows:
            # 超过17点，后面的的人站进了黄线的人被赶出去
            if time >= 6 * 90 and len(window.q) > 1:
                for c in window.q[1:]:
                    waitingList.append(c)
                    window.q.remove(c)

            if len(window.q) > 0:
                window.q[0].remain -= timePass
                # 所有已经处理完的人离开窗口，并记录结束时间戳到结束信息表中
                if window.q[0].remain == 0:
                    hour = 8 + floor(time / 60)
                    minute = time % 60
                    finishDict[window.q[0].id] = f"{hour:02d}:{minute:02d}\n"
                    window.q.pop(0)
                    # 上一个客户走了之后窗口前有了新的容量
                    window.remain += 1

    # 剩下的人全部超时
    for c in waitingList:
        finishDict[c.id] = "Sorry\n"

    # 最后输出的字符串
    result = ""
    for query in queries:
        result += finishDict[query]

    print(result, end='')


if __name__ == '__main__':
    summit()
