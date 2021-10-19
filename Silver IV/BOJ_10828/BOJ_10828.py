import sys
from collections import deque

if __name__ == "__main__":
    stack = deque()

    n = int(sys.stdin.readline())
    info = [sys.stdin.readline().strip() for _ in range(n)]

    # print(info)

    for row in info:
        if row == "top":
            if stack:
                value = stack.pop()
                print(value)
                stack.append(value)
            else:
                print(-1)
        elif row == "pop":
            if stack:
                print(stack.pop())
            else:
                print(-1)
        elif row == "size":
            print(len(stack))
        elif row[0:4] == "push":
            stack.append(int(row[5:]))
        elif row == "empty":
            if stack:
                print(0)
            else:
                print(1)
