tc = int(input())

for _ in range(tc):
    s = input()

    ans = 0
    stream = 1
    for ch in s:
        if ch == 'O':
            ans += stream
            stream += 1
        else:
            stream = 1

    print(ans)
