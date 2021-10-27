import sys


def binarySearch(low, high, info, m):
    ret = 0

    while low <= high:
        mid = (low + high) >> 1
        # print(mid)

        sum = 0

        for val in info:
            if val > mid:
                sum += val - mid

        if sum >= m:
            ret = max(ret, mid)
            low = mid + 1
        else:
            high = mid - 1

    return ret


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    info = list(map(int, sys.stdin.readline().split()))

    print(binarySearch(1, max(info), info, m))
