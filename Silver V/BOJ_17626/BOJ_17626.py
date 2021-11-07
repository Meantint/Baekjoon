import sys


def init(dp):
    dp[0] = 0
    # print(dp)
    for i in range(1, 250):
        start = i * i

        # print(start)
        for val in range(start, 50001, 1):
            # print(dp[val], dp[val - start])
            dp[val] = min(dp[val], dp[val - start] + 1)
            # print(dp[val])


if __name__ == "__main__":
    dp = [100000] * 50001
    init(dp)
    # print(dp)

    n = int(sys.stdin.readline())

    print(dp[n])
