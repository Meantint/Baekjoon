n = int(input())
string = input()

ans = 0
for idx in range(n):
    ans += (ord(string[idx]) - 96) * (31 ** idx)
print(ans % 1234567891)
# print(ans)
