def summit():
    """

    """
    string = input()
    numSign = string[0]
    num, exp = string[1:].split("E")
    exp = int(exp)

    if exp == 0:
        print(numSign + num)
    elif exp > 0:
        pass
    elif exp < 0:
        pass


if __name__ == '__main__':
    summit()