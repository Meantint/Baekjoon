# BOJ_1003 - 피보나치 함수

&nbsp;`DP`로 풀었다.

## 문제/코드 링크

- [BOJ_1003 - 피보나치 함수](https://www.acmicpc.net/problem/1003)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `dp[i].first` : `i`번째 수의 `0`이 출력되는 횟수

- `dp[i].second` : `i`번째 수의 `1`이 출력되는 횟수

- 미리 `40`번째까지 `dp`에 저장해놓는다.

## Code

```cpp
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int t, n;
vector<PII> dp(41);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[0] = make_pair(1, 0);
    dp[1] = make_pair(0, 1);
    for (int i = 2; i < 41; ++i) {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n].first << ' ' << dp[n].second << '\n';
    }

    return 0;
}
```
