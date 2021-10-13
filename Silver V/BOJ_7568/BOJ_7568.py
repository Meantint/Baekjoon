import sys

n = int(sys.stdin.readline())
info = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

# print(info)

ans = [1] * len(info)
for i in range(n):
    for j in range(i + 1, n):
        if info[i][0] > info[j][0] and info[i][1] > info[j][1]:
            ans[j] += 1
        elif info[i][0] < info[j][0] and info[i][1] < info[j][1]:
            ans[i] += 1

print(*ans)
