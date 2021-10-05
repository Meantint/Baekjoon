def GCD(v1, v2):
    if v1 % v2 == 0:
        return v2
    return GCD(v2, v1 % v2)


a, b = map(int, input().split())

gcd = GCD(a, b)
print(gcd)
print(a * b // gcd)
