import sys
from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

n, m = map(int, input().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
target = [[False] * m for _ in range(n)]


def isSafe(y, x):
    if 0 <= y < n and 0 <= x < m:
        return True
    return False


def isClean():
    for r in range(n):
        for c in range(m):
            if board[r][c] == 1:
                return False
    return True


def UpdateOutside():
    isVisited = [[False] * m for _ in range(n)]
    queue = deque()

    queue.append([0, 0])
    isVisited[0][0] = True

    while queue:
        # print(queue.popleft())
        y, x = queue.popleft()

        for i in range(4):
            cy = y + dy[i]
            cx = x + dx[i]

            if isSafe(cy, cx) and board[cy][cx] != 1 and not isVisited[cy][cx]:
                queue.append([cy, cx])
                board[cy][cx] = -1
                isVisited[cy][cx] = True


answer = 0
while not isClean():
    UpdateOutside()

    for r in range(n):
        for c in range(m):
            if board[r][c] == 1:
                cntOutside = 0
                for i in range(4):
                    cy = r + dy[i]
                    cx = c + dx[i]
                    if isSafe(cy, cx) and board[cy][cx] == -1:
                        cntOutside += 1

                if cntOutside >= 2:
                    board[r][c] = 0

                cntOutside = 0

    answer += 1

print(answer)
