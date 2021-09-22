tc = int(input())

for _ in range(tc):
    ans = ''
    r, s = input().split()
    for ch in s:
        ans += ch * int(r)
    print(ans)
