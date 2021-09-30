while True:
    n = input()

    if n == "0":
        break

    n = list(map(str, n))

    length = len(n)

    ans = "yes"
    for idx in range(length):
        if idx >= length - idx - 1:
            break
        if n[idx] != n[length - idx - 1]:
            ans = "no"
            break

    print(ans)
