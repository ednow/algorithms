from functools import reduce


def summit():
    mapper = {
        0: "W",
        1: "T",
        2: "L"
    }
    maxOdds = []
    for _ in range(3):
        maxOdds.append(
            max(
                [(idx, float(i)) for idx, i in enumerate(input().split())],
                key=lambda x: x[1]
            )
        )
    print(f"{' '.join(mapper[x[0]] for x in maxOdds)} {(reduce(lambda a,b:a * b[1], maxOdds, 1)*0.65 - 1)*2:.2f}", end="")


if __name__ == '__main__':
    summit()
