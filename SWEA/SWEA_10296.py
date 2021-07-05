n = int(input())

answer = []
for i in range(1, n + 1):
    cnt = 0
    for j in str(i):
        if j == '3' or j == '6' or j == '9':
            cnt += 1

    if cnt > 0:
        answer.append('짝' * cnt)
    else:
        answer.append(i)

for i in answer:
    print(i, end=' ')
# print(answer)
# print(' '.join(map(str, answer)))
