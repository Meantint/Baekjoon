s = input()

answer = {"UPPER CASE": 0, "LOWER CASE": 0}

for i in s:
    if 'A' <= i <= 'Z':
        answer["UPPER CASE"] += 1
    elif 'a' <= i <= 'z':
        answer["LOWER CASE"] += 1
for key, val in answer.items():
    print("{0} {1}".format(key, val))
