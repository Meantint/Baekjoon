import sys


def BS(target: int, info: list):
    lo = 0
    hi = len(info) - 1

    while lo <= hi:
        mid = (lo + hi) >> 1

        if info[mid] == target:
            return True
        elif info[mid] > target:
            hi = mid - 1
        else:
            lo = mid + 1

    return False


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    info = list(map(int, sys.stdin.readline().split()))
    info.sort()

    m = int(sys.stdin.readline())
    for _ in range(m):
        target = list(map(int, sys.stdin.readline().split()))

        for tg in target:
            if BS(tg, info):
                print(1)
            else:
                print(0)
