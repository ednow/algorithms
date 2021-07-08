def summit():
    num, head = map(int, input().split())
    l = []
    for _ in range(num):
        l.append(input().split())
    l.sort(key=lambda x: int(x[1]))
    # 更改指针
    for i in range(1, len(l)):
        l[i-1][2] = l[i][0]
    l[num-1][2] = "-1"
    print(f"{num} {l[0][0]}")
    for i in l:
        print(" ".join(i))


if __name__ == '__main__':
    summit()
