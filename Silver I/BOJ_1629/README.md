# BOJ_1629 - 곱셈

&nbsp;분할정복을 이용해 풀었다.

- Baekjoon - [곱셈](https://www.acmicpc.net/problem/1629)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `b`가 `1`이라면 `a % c`를 리턴한다.

- `b`가 `2`라면 `(a * a) % c`를 리턴한다.

- `b`가 짝수인 경우 `(solve(a, b / 2, c) * solve(a, b / 2, c)) % c`를 리턴한다.

- `b`가 홀수인 경우 `(solve(a, b - 1, c) * a) % c`를 리턴한다.

## Code

```cpp
#include <cmath>
#include <iostream>

using namespace std;

long long solve(long long a, long long b, long long c)
{
    if (b == 1) {
        return a % c;
    }
    if (b == 2) {
        return (a * a) % c;
    }
    // 짝수라면
    if (b % 2 == 0) {
        return (solve(a, b / 2, c) * solve(a, b / 2, c)) % c;
    }
    // 홀수라면
    else {
        return (solve(a, b - 1, c) * a) % c;
    }
}

int main()
{
    long long a, b, c;

    cin >> a >> b >> c;
    cout << solve(a, b, c) << '\n';

    return 0;
}
```
