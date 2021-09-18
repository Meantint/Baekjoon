m, n = map(int, input().split())

# Python의 list는 개수를 늘릴 때도 곱하기 연산이 사용가능하다.
isPrime = [True] * (n + 1)

for i in range(2, n + 1, 1):
    for j in range(i * i, n + 1, i):
        isPrime[j] = False

for i in range(m, n + 1):
    if isPrime[i] is True:
        print(i)
