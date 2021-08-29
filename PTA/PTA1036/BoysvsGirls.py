def summit():
    answer = {
        # 男性的最低成绩者
        "M": {
            "score": float("inf"),
            "name": "",
            "subject": "",

        },
        "F": {
            "score": -1,
            "name": "",
            "subject": "",
        }
    }
    for _ in range(int(input())):
        name, gender, subject, score = input().split()
        score = int(score)

        if gender == "M":
            if score < answer[gender]["score"]:
                answer[gender]["score"] = score
                answer[gender]["subject"] = subject
                answer[gender]["name"] = name

        else:
            if score > answer[gender]["score"]:
                answer[gender]["score"] = score
                answer[gender]["subject"] = subject
                answer[gender]["name"] = name

    absent = False
    for gender in ["F", "M"]:
        if answer[gender]["name"] == "":
            print("Absent")
            absent = True
        else:
            print(f"{answer[gender]['name']} {answer[gender]['subject']}")

    if absent:
        print("NA", end="")
    else:
        print(f"{answer['F']['score'] - answer['M']['score']}", end="")


if __name__ == '__main__':
    summit()
