s = input()

answer = {"LETTERS": 0, "DIGITS": 0}

for i in s:
    if 'a' <= i <= 'z' or 'A' <= i <= 'Z':
        answer["LETTERS"] += 1
    elif '0' <= i <= '9':
        answer["DIGITS"] += 1
for key, val in answer.items():
    print("{0} {1}".format(key, val))
