dp = [0] * 1000001


def divSum(val):
    ret = int(val)
    for ch in str(val):
        ret += int(ch)

    return ret


def init():
    for i in range(1000000, 0, -1):
        temp = divSum(i)
        if temp <= 1000000:
            dp[temp] = i


init()
n = int(input())

print(dp[n])
