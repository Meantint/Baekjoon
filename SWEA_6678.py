cnt = 0
while True:
    s = input()
    if not s:
        break
    print(">> {0}".format(s.upper()))
    cnt += 1
    if cnt == 3:
        break
