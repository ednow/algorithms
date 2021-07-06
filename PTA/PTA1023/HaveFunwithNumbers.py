def summit():
    string = input()
    result = ""
    rawNums = set(string)
    doubledResult = 2 * int(string)
    doubledNums = set(str(doubledResult))
    intersectionLen = len(rawNums) - len(doubledNums)
    print(f"{'Yes' if intersectionLen == 0 else 'No'}\n{doubledResult}", end="")


if __name__ == '__main__':
    summit()
