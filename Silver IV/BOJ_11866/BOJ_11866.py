import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
queue = deque([idx for idx in range(1, n + 1)])


print("<", end="")
cycle = 0
cnt = 0
while queue:
    value = queue.popleft()

    cycle += 1
    if cycle == m:
        cnt += 1
        cycle = 0

        if cnt == n:
            print(value, end="")
        else:
            print(value, end=", ")
    else:
        queue.append(value)

print(">")
