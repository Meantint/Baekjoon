n = int(input())

ans = -1

for i in range(n):
    if i * 3 > n:
        break

    temp = n - i * 3
    if temp % 5 == 0:
        ans = i + temp // 5
        break

print(ans)
