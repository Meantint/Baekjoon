# BOJ_11727 - 2×n 타일링 2

&nbsp;`DP` 문제

## 문제/코드 링크

- [BOJ_11727 - 2×n 타일링 2](https://www.acmicpc.net/problem/11727)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `dp[i] = dp[i - 1] + dp[i - 2] * 2, (i > 3)`

  - `dp[i - 2]`의 경우에는 `2`를 곱하는데 `2 * 2` 모양을 만드는데 총 3가지 경우가 있다. 하지만 `1 * 2`로 2개를 놓는 경우는 `dp[i - 1]`까지의 모양과 겹치는 경우가 생기므로 1개를 빼줘야한다.

## Code

```cpp
#include <iostream>
#include <vector>

#define MOD 10007

using namespace std;

int n;
vector<int> dp(1001, 0);

void init()
{
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i < 1001; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] * 2;
        dp[i] %= MOD;
    }
}

int main()
{
    init();

    cin >> n;
    cout << dp[n] << '\n';

    return 0;
}
```
