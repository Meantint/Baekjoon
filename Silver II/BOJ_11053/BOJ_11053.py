# Input
n = int(input())
cost = list(map(int, input().split()))

# Init
dp = [cost[0]]

for i in range(1, n):
    curIdx = len(dp) - 1
    while curIdx >= 0 and dp[curIdx] >= cost[i]:
        curIdx -= 1
    curIdx += 1

    if len(dp) == curIdx:
        dp.append(cost[i])
    else:
        dp[curIdx] = cost[i]

print(len(dp))
# print(dp)
