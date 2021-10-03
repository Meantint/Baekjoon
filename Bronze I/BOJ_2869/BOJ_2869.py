a, b, v = map(int, input().split())

v -= a
cycle = a - b

ans = v // cycle + 1
if v % cycle != 0:
    ans += 1

print(ans)
