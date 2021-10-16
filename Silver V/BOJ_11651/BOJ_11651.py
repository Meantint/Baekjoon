import sys

n = int(sys.stdin.readline())
info = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

info.sort(key=lambda x: (x[1], x[0]))
for el in info:
    print(*el)
