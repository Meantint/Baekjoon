import sys
from collections import deque

if __name__ == "__main__":
    queue = deque()

    n = int(sys.stdin.readline())
    info = [sys.stdin.readline().strip() for _ in range(n)]

    # print(info)

    for row in info:
        if row == "pop":
            if queue:
                print(queue.popleft())
            else:
                print(-1)
        elif row == "size":
            print(len(queue))
        elif row[0:4] == "push":
            queue.append(int(row[5:]))
        elif row == "back":
            if queue:
                value = queue.pop()
                print(value)
                queue.append(value)
            else:
                print(-1)
        elif row == "empty":
            if queue:
                print(0)
            else:
                print(1)

        elif row == "front":
            if queue:
                value = queue.popleft()
                print(value)
                queue.appendleft(value)
            else:
                print(-1)
