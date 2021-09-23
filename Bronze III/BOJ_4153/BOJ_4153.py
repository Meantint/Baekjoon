while True:
    info = list(map(int, input().split()))

    if info == [0, 0, 0]:
        break

    info.sort()

    if info[0] ** 2 + info[1] ** 2 == info[2] ** 2:
        print('right')
    else:
        print('wrong')
