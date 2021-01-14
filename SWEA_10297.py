n = int(input())

answer = []
for i in range(n):
    answer.append((i + 1) * 3)

answer.reverse()
print(' '.join(map(str, answer)))
