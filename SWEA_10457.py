tc = int(input())

answer = {}
for i in range(tc):
    val, key = map(str, input().split())
    if key in answer:
        if val not in answer[key]:
            answer[key].append(val)
    else:
        answer[key] = [val]

q = input()
print(' '.join(answer[q]))
