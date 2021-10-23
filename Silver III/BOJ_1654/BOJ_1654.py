import sys


def binarySearch(info, k):
    answer = 0

    low = 1
    high = max(info)
    # print(low, high)

    while low <= high:
        mid = (low + high) >> 1
        # print(mid)

        total = 0
        for row in info:
            total += row // mid

        if total >= k:
            if answer < mid:
                answer = mid
            low = mid + 1
        else:
            high = mid - 1

    return answer


if __name__ == "__main__":
    n, k = map(int, sys.stdin.readline().split())
    info = [int(sys.stdin.readline()) for _ in range(n)]

    # print(n, k, info)
    print(binarySearch(info, k))
