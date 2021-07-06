def summit():
    string = input()
    result = 0
    q = list(map(int, string.split()))[1:]
    for now, destination in zip(([0]+q)[:-1], q):
        if now > destination:
            result += (now - destination) * 4
        else:
            result += (destination - now) * 6
        result += 5
    print(f"{result}", end="")


if __name__ == '__main__':
    summit()
