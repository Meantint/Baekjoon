count = [-1 for _ in range(26)]

info = list(input())
# print(info)

base = ord('a')
for idx in range(len(info)):
    # print(info[idx])
    cur = ord(info[idx])
    if count[cur - base] == -1:
        count[cur - base] = idx

print(*count)
