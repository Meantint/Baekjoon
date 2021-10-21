import sys
from collections import deque

if __name__ == "__main__":
    dq = deque()

    n = int(sys.stdin.readline())
    info = [sys.stdin.readline().strip() for _ in range(n)]

    # print(info)

    for row in info:
        if row == "size":
            print(len(dq))
        elif row == "back":
            if dq:
                value = dq.pop()
                print(value)
                dq.append(value)
            else:
                print(-1)
        elif row == "empty":
            if dq:
                print(0)
            else:
                print(1)
        elif row == "front":
            if dq:
                value = dq.popleft()
                print(value)
                dq.appendleft(value)
            else:
                print(-1)
        elif row == "pop_back":
            if dq:
                print(dq.pop())
            else:
                print(-1)
        elif row == "pop_front":
            if dq:
                print(dq.popleft())
            else:
                print(-1)
        elif row[0:9] == "push_back":
            dq.append(int(row[10:]))
        elif row[0:10] == "push_front":
            dq.appendleft(int(row[11:]))
