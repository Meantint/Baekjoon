import sys

n = int(sys.stdin.readline())


curCount = 0
curNum = 1
while True:
    curString = str(curNum)
    if curString.find("666") != -1:
        curCount += 1
        if curCount == n:
            print(curNum)
            break
    curNum += 1
