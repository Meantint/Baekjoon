import sys
from collections import deque

n = int(sys.stdin.readline())
info = [sys.stdin.readline().strip() for _ in range(n)]

# print(info)

for row in info:
    stack = deque()
    for col in row:
        if col == "(":
            stack.append(col)
        else:
            if not stack or stack.pop() != "(":
                stack.append("$")

    if stack:
        print("NO")
    else:
        print("YES")
