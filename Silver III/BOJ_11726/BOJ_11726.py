import sys

if __name__ == "__main__":
    dp = [0] * 1001
    dp[1] = 1
    dp[2] = 2
    # print(dp)

    for i in range(3, 1001):
        dp[i] = dp[i - 1] + dp[i - 2]
        dp[i] %= 10007

    n = int(sys.stdin.readline())

    print(dp[n])
