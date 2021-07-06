def summit():
    """
    假设地x个相同大写字母,出现在字符串的同一个位置
    """
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    alphabet = alphabet.lower() + alphabet
    weekBet = "ABCDEFG"
    hourBet = "0123456789ABCDEFGHIJKLMN"
    weekDay = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
    string1 = input().strip()
    string2 = input().strip()
    string3 = input().strip()
    string4 = input().strip()
    maxLen1 = min(len(string1), len(string2))
    maxLen2 = min(len(string3), len(string4))
    week = ''
    hours = 0
    minutes = 0

    isSelectWeek = True  # 是否是挑选星期
    for a, b in zip(string1[:maxLen1], string2[:maxLen1]):
        if a == b:
            if isSelectWeek and a in weekBet:
                week = weekDay[weekBet.find(a)]
                isSelectWeek = False
            elif not isSelectWeek and a in hourBet:
                hours = hourBet.find(a)
                break

    for idx, (a, b) in enumerate(zip(string3[:maxLen2], string4[:maxLen2])):
        if a == b:
            if a in alphabet:
                minutes = idx
                break

    print(f"{week} {hours:>02d}:{minutes:>02d}")


if __name__ == '__main__':
    summit()