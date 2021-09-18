import sys

n = int(input())
# Python에서의 sys.stdin.readline()은 C++에서의 ios::sync_with_stdio(0); cin.tie(0)의 역할을 한다.
info = [int(sys.stdin.readline()) for i in range(n)]
info.sort()

for i in info:
    print(i)
