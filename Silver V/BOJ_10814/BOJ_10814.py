import sys

n = int(sys.stdin.readline())

info = [list(sys.stdin.readline().split()) for _ in range(n)]
info.sort(key=lambda x: int(x[0]))

for ans in info:
    print(ans[0], ans[1])
