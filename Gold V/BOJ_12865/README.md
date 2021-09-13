# BOJ_12865 - 평범한 배낭

&nbsp;`DP`를 이용해서 풀었다.

## 문제/코드 링크

- [BOJ_12865 - 평범한 배낭](https://www.acmicpc.net/problem/12865)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 점화식 : `dp[i] = max(dp[i], dp[i - w[j]] + v[j])`

  - `j`번째 물건을 넣은 것과 안넣은 것 중 더 값이 큰 것을 `dp[i]`에 저장한다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> w, v;
vector<int> dp;

int main()
{
    cin >> n >> k;
    w.resize(n);
    v.resize(n);
    dp.resize(k + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = k; j > 0; --j) {
            if (w[i] <= j) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[k] << '\n';

    return 0;
}
```
