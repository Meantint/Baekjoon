n, m = map(int, input().split())
info = list(map(int, input().split()))

ans = 0

# print(n, m, *info)


def dfs(idx, cnt, val):
    val += info[idx]
    cnt += 1

    if cnt == 3:
        global ans
        if ans < val <= m:
            ans = val
        return

    for i in range(idx + 1, n):
        dfs(i, cnt, val)


for i in range(0, n):
    dfs(i, 0, 0)

print(ans)
