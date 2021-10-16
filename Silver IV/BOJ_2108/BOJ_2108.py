import sys
from collections import Counter

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    info = [int(sys.stdin.readline()) for _ in range(n)]

    info.sort()

    ans = [
        round(sum(info) / len(info)),
        info[len(info) // 2],
        info[-1] - info[0],
    ]

    mtcList = list(Counter(info).most_common())
    if len(mtcList) == 1:
        ans.insert(2, mtcList[0][0])
    elif mtcList[0][1] == mtcList[1][1]:
        ans.insert(2, mtcList[1][0])
    else:
        ans.insert(2, mtcList[0][0])

    print(*ans, sep="\n")
