import sys


def init():
    isPrime = [True for _ in range(1000001)]
    isPrime[0] = isPrime[1] = False

    for i in range(1000001):
        if isPrime[i]:
            for j in range(i * i, 1000001, i):
                isPrime[j] = False

    return isPrime


is_prime = init()
n, m = list(map(int, sys.stdin.readline().split()))
# print(n, m)

for i in range(n, m + 1):
    if is_prime[i]:
        print(i)
