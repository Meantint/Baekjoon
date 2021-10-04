n = int(input())
info = list(set([input() for _ in range(n)]))

info.sort(key=lambda word: (len(word), word))

for ans in info:
    print(ans)
