import sys

n, m = map(int, sys.stdin.readline().split())
# print(n, m)

info = [sys.stdin.readline().strip() for _ in range(n)]

# print(info)

ans = 100

letter = ["W", "B"]

for r in range(n):
    if r + 7 >= n:
        break
    for c in range(m):
        if c + 7 >= m:
            break

        count = 0
        for i in range(8):
            for j in range(8):
                check = letter[(i + j) % 2]
                # print(info[r + i][c + j])
                # print(check)
                if info[r + i][c + j] != check:
                    # print("diff diff")
                    count += 1

        if ans > count:
            ans = count
        if ans > (64 - count):
            ans = 64 - count

print(ans)
