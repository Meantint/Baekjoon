import sys
from collections import Counter

n = int(sys.stdin.readline())
info = list(map(int, sys.stdin.readline().split()))

# print(info)
# print(Counter(info))

cntInfo = Counter(info)

m = int(sys.stdin.readline())
mInfo = list(map(int, sys.stdin.readline().split()))

for col in mInfo:
    print(cntInfo[col], end=" ")
