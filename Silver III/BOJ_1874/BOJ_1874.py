import sys
from collections import deque

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    info = [int(sys.stdin.readline()) for _ in range(n)]

    stack = deque()
    start = [i for i in range(1, n + 1)]

    answer = []

    infoIdx = 0
    startIdx = 0
    while True:
        # print(infoIdx, startIdx)
        if not stack:
            if startIdx == n:
                break
            stack.append(start[startIdx])
            startIdx += 1
            answer.append("+")
        else:
            if infoIdx == n:
                break
            value = stack.pop()
            if value == info[infoIdx]:
                infoIdx += 1
                answer.append("-")
            else:
                stack.append(value)
                if startIdx == n:
                    break
                stack.append(start[startIdx])
                startIdx += 1
                answer.append("+")

    if len(answer) != n * 2:
        print("NO")
    else:
        print(*answer, sep="\n")
