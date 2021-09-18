import sys

n = int(input())
# Python은 split 안에 원하는 문자를 입력하면 그 문자를 기준으로 입력을 나눠준다.
info = [list(map(int, sys.stdin.readline().split(' '))) for i in range(n)]

info.sort()

# Python은 받는 인자로(C++에서 for(int i = 0; ; ++i)에서의 i) 여러개를 받을 수 있다.
for x, y in info:
    print(x, y)
