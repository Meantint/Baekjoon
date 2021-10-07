import sys


def init():
    isPrime = [True for _ in range(1001)]
    isPrime[0] = isPrime[1] = False

    for idx in range(1001):
        if isPrime[idx]:
            for idx2 in range(idx * idx, 1001, idx):
                isPrime[idx2] = False

    return isPrime


ans = 0
is_prime = init()

n = sys.stdin.readline()
info = list(map(int, sys.stdin.readline().split()))

for idx in info:
    if is_prime[idx] == True:
        ans += 1

print(ans)
