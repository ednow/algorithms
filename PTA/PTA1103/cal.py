from functools import reduce


if __name__ == '__main__':
    l = [5, 3, 2, 2]
    p = 3
    print(reduce(lambda a, b: a + b ** p, l, 0))
