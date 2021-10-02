n, k = map(int, input().split())

if n - k < k:
    k = n - k

ans = 1
for i in range(k):
    ans *= n - i
for i in range(1, k + 1):
    ans //= i

print(ans)
