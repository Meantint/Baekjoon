def init():
    return [i for i in range(15)]


for _ in range(int(input())):
    dp = init()

    k = int(input())
    n = int(input())

    for _ in range(k):
        for c in range(1, n + 1):
            dp[c] += dp[c - 1]

    # for val in dp:
    #     print(val, end=' ')
    # print()
    print(dp[n])
