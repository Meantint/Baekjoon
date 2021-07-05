s = input()
answer = {}
for i in s:
    if i in answer:
        answer[i] += 1
    elif i not in answer:
        answer[i] = 1
for key, val in answer.items():
    print("{0},{1}".format(key, val))
