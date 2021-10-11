import sys
from collections import deque

k = int(sys.stdin.readline())

deq = deque()
for _ in range(k):
    num = int(sys.stdin.readline())
    if num == 0:
        deq.pop()
    else:
        deq.append(num)

# print(deq)
print(sum(deq))