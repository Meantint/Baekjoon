info = list(map(int, input().split()))

value = 0
for i in info:
    value += i ** 2

print(value % 10)
