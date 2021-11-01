# BOJ_13172 - Σ

&nbsp;분할정복 문제. 기약분수가 아닐 수도 있으므로 최대공약수로 나눠주는 작업까지 해줘야한다.

## 문제/코드 링크

- [BOJ_13172 - Σ](https://www.acmicpc.net/problem/13172)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 기약분수로 만들기 위해서 최대공약수를 구해준다.

  - 최대공약수를 구해주는 함수 `gcd`를 만들었다.

- 빠른 거듭제곱 계산을 위해 분할정복을 이용하였다.

  - 분할정복을 이용한 계산을 해주는 함수 `dc`를 만들었다.

- 각 주사위의 기댓값을 `answer`에 더해준다.

  - `answer` 역시도 `MOD`로 계속 나머지만 남기면서 갱신해줘야 한다.

    - 이 부분은 문제에 자세한 내용이 없다고 생각해서 조금 헷갈린다.

## Code

```cpp
#include <iostream>

#define ll long long
#define MOD 1000000007

using namespace std;

int m;
ll n, s;

ll dc(int cnt)
{
    if (cnt == 1) {
        return n;
    }
    if (cnt % 2 == 0) {
        ll value = dc(cnt / 2);
        return value * value % MOD;
    }
    else {
        return dc(cnt - 1) * n % MOD;
    }
}

ll gcd(ll x, ll y)
{
    if (x % y == 0) {
        return y;
    }
    return gcd(y, x % y);
}

int main()
{
    cin >> m;

    ll answer = 0;
    while (m--) {
        cin >> n >> s;

        ll curGCD = gcd(n, s);
        n /= curGCD;
        s /= curGCD;

        // cout << dc(MOD - 2) << '\n';
        // cout << dc(MOD - 2) * s << '\n';
        // cout << dc(MOD - 2) * s % MOD << '\n';
        // cout << (dc(MOD - 2) * s) % MOD << '\n';

        answer += (dc(MOD - 2) * s % MOD);
        answer %= MOD;
    }
    cout << answer << '\n';

    return 0;
}
```
