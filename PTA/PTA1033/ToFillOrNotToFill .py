def summit():
    pass


if __name__ == '__main__':
    # summit()
    # print(
    #     150 / 12 * 7.10 +
    #     150 / 12 * 7 +
    #     300 / 12 * 6.85 +
    #     400 / 12 * 7.00 +
    #     250 / 12 * 7.5 +
    #     50 / 12 * 6.00
    # )

    # 在300的地方要加满,在600的地方也要加满
    # 750.0
    # print(
    #     150 / 12 * 7.10 +
    #     150 / 12 * 7 +
    #     50 * 6.85 +
    #     300 / 12 * 7.00 +
    #     50 / 12 * 7.5 +
    #     50 / 12 * 6.00
    # )

    print(
        (150 * 7.10 +  # 起始站，只加到150m那个油站的油
         150 * 7 +  # 150m油站，只加到300m那个油站的油
         600 * 6.85 +  # 300m油站，加满油
         300 * 7.00 +  # 600m油站，加满油
         50 * 7.3 +  # 1000m油站,加到1250m油站的油
         50 * 6.00) / 12  # 加到终点的油
    )