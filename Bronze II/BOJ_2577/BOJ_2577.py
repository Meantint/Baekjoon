from collections import Counter

info = [int(input()) for _ in range(3)]

value = 1
for v in info:
    value *= v

ans = dict(Counter(list(str(value))))
# print(ans)
# print(type(ans))
for i in range(10):
    # print(i)
    # print(type(str(i)))
    # print(ans['0'])
    if str(i) in ans:
        print(ans[str(i)])
    else:
        print(0)
