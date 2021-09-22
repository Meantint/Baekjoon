from collections import Counter

info = [int(input()) % 42 for _ in range(10)]

ans = dict(Counter(info))
# print(ans)

print(len(ans))
