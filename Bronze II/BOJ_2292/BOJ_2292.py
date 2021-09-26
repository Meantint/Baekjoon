n = int(input())

n -= 1
cnt = 1

while n > 0:
    n -= 6 * cnt
    cnt += 1

print(cnt)
