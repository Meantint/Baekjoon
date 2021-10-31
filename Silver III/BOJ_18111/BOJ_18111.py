import sys


def bruteForce(board, b):
    ret = [3000000000, -1]
    for h in range(0, 257):
        curBlock = b
        # print(h, ret)

        time = 0
        for row in board:
            for col in row:
                if col > h:
                    time += (col - h) * 2
                elif col < h:
                    time += h - col
                curBlock += col - h
        if curBlock < 0:
            continue
        if ret[0] > time:
            ret = [time, h]
        elif ret[0] == time:
            if ret[1] < h:
                ret[1] = h

    return ret


if __name__ == "__main__":
    n, m, b = map(int, sys.stdin.readline().split())
    board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

    # print(board)

    print(*bruteForce(board, b))
