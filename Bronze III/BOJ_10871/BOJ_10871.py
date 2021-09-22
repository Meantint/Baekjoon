n, x = map(int, input().split())
info = list(map(int, input().split()))

ans = [cur for cur in info if cur < x]

print(*ans)
