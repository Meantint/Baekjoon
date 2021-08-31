# BOJ_1929 - 소수 구하기

&nbsp;에라토스테네스의 체를 이용하면된다.

## 문제/코드 링크

- [BOJ_1929 - 소수 구하기](https://www.acmicpc.net/problem/1929)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `index`가 소수인지 아닌지 판별하는 `isPrime` 함수를 만들었다.

- `2` ~ `m`까지의 소수를 갱신한 후 `n` ~ `m`을 탐색하면서 소수라면 출력해준다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<bool> isPrime(1000001, true);

int main()
{
    cin >> n >> m;

    isPrime[1] = false;
    for (int i = 2; i <= m; ++i) {
        if (!isPrime[i]) {
            continue;
        }
        for (int j = i * 2; j <= m; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = n; i <= m; ++i) {
        if (isPrime[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}
```
