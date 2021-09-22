asc = [i for i in range(1, 9)]
desc = [i for i in range(8, 0, -1)]

info = list(map(int, input().split()))

if info == asc:
    print('ascending')
elif info == desc:
    print('descending')
else:
    print('mixed')
