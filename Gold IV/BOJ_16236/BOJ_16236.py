import sys
from collections import deque

sharkSize = 2
needShark = 2

myPos = []  # 아기 상어 pos
anotherPos = []  # 다른 상어 pos, size

answer = 0

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

n = int(sys.stdin.readline())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]


def isSafe(y, x):
    global n
    if 0 <= y < n and 0 <= x < n:
        return True
    return False


def BFS():
    global myPos, anotherPos, sharkSize, needShark, answer, board, dy, dx
    while True:
        isVisited = [
            [False] * n for _ in range(n)
        ]  # [[False] * n] * n으로 만들어서 에러 찾는데 하루종일 걸렸다. 아직도 모름
        queue = deque()

        isVisited[myPos[0]][myPos[1]] = True
        queue.append([myPos[0], myPos[1], 0])

        isPos = []
        while queue:
            y, x, dist = queue.popleft()

            if board[y][x] > sharkSize:
                continue
            if 0 < board[y][x] < sharkSize:
                isPos.append([y, x, dist])

            for i in range(4):
                cy = y + dy[i]
                cx = x + dx[i]

                if isSafe(cy, cx) and not isVisited[cy][cx]:
                    isVisited[cy][cx] = True
                    queue.append([cy, cx, dist + 1])

        # 옮길 수 있는 위치가 없다면
        if not isPos:
            return

        isPos.sort(key=lambda c: (c[2], c[0], c[1]))

        # 옮길 수 있는 위치가 하나라도 있는 경우 시행
        board[isPos[0][0]][isPos[0][1]] = 0
        myPos = isPos[0][:2]
        answer += isPos[0][2]
        needShark -= 1
        if needShark == 0:  # 사이즈 키우기에 필요한 만큼의 상어를 해치웠다면
            sharkSize += 1
            needShark = sharkSize


if __name__ == "__main__":
    for r in range(n):
        for c in range(n):
            if board[r][c] == 9:
                myPos = [r, c]
                board[r][c] = 0
            elif 0 < board[r][c]:
                anotherPos.append([r, c])

    BFS()

    print(answer)
