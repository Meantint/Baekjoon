import sys
from collections import deque

if __name__ == "__main__":
    info = []
    while True:
        info.append(sys.stdin.readline().rstrip())

        if info[-1] == ".":
            info.pop()
            break

    for row in info:
        stack = deque()

        for col in row:
            if col == "[" or col == "(":
                stack.append(col)
            elif col == "]":
                if not stack:
                    stack.append("$")
                    break
                ch = stack.pop()
                if ch != "[":
                    stack.append("$")
                    break
            elif col == ")":
                if not stack:
                    stack.append("$")
                    break
                ch = stack.pop()
                if ch != "(":
                    stack.append("$")
                    break
        if not stack:
            print("yes")
        else:
            print("no")
