import sys
from collections import deque

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    queue = deque()
    for i in range(1, n + 1):
        queue.append(i)

    case = 0
    while len(queue) != 1:
        if case == 0:
            val = queue.popleft()
            # print(f"#{val} is deleted")
        else:
            queue.append(queue.popleft())
            # print(f"#{val} is moved last index")

        case = (case + 1) % 2

    print(queue.pop())
