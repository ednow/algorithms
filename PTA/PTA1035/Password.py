def summit():
    mapper = {
        "1": "@",
        "0": "%",
        "l": "L",
        "O": "o"
    }
    num = int(input())
    teams = {}
    updateTeams = {}
    for i in range(num):
        teams.update({
            k: v for k, v in [input().split()]
        })
    modifyNum = 0
    for k, v in teams.items():
        vRaw = v
        for k1, v1 in mapper.items():
            v = v.replace(k1, v1, )
        if vRaw != v:
            modifyNum += 1
            updateTeams.update({k:v})
    updateInfo = "\n".join([f"{k} {v}" for k,v in updateTeams.items()])
    if len(updateTeams) == 0 and len(teams) == 1:
        print("There is 1 account and no account is modified")
    elif len(updateTeams) == 0 and len(teams) > 1:
        print(f"There are {len(teams)} accounts and no account is modified")
    else:
        print(f"{len(updateTeams)}\n{updateInfo}")


if __name__ == '__main__':
    summit()