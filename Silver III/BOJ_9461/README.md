# BOJ_9461 - 파도반 수열

&nbsp;

## 문제/코드 링크

- [BOJ_9461 - 파도반 수열](https://www.acmicpc.net/problem/9461)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `DP` 문제이다.

- `dp[i] = dp[i - 1] + dp[i - 5], (i > 5)`

## Code

```cpp
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int tc;
vector<ll> dp(101, 0);

void init()
{
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    for (int i = 6; i <= 100; ++i) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    return;
}

int main()
{
    init();

    cin >> tc;
    while (tc--) {
        int num;
        cin >> num;

        cout << dp[num] << '\n';
    }

    return 0;
}
```
