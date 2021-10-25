import sys
from collections import deque, Counter

if __name__ == "__main__":
    tc = int(sys.stdin.readline())
    for _ in range(tc):
        n, target = map(int, sys.stdin.readline().split())
        info = list(map(int, sys.stdin.readline().split()))

        counter = sorted(Counter(info).items(), reverse=True)
        newInfo = [list(elem) for elem in counter]

        # print(*newInfo)

        newInfoIdx = 0
        infoIdx = 0
        cnt = 1
        while True:
            # 우선순위 일치
            if info[infoIdx] == newInfo[newInfoIdx][0]:
                # 현재 인덱스가 타겟 인덱스라면 몇번째인지 출력하고 while문 종료
                if infoIdx == target:
                    print(cnt)
                    break

                cnt += 1
                newInfo[newInfoIdx][1] -= 1
                info[infoIdx] = -1

                infoIdx = (infoIdx + 1) % n
                # 최우선순위의 남은 개수가 0개라면
                if newInfo[newInfoIdx][1] == 0:
                    newInfoIdx += 1
            else:
                infoIdx = (infoIdx + 1) % n
