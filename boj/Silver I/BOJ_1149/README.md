# BOJ_1149 - RGB거리

&nbsp;`DP`를 이용해 풀었다.

- Baekjoon - [RGB거리](https://www.acmicpc.net/problem/1149)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 비용을 담아두는 `vector<vector<int>>` 변수 `cost`와 `i`까지의 최소 비용을 담아두는 `vector<vector<int>>` 변수 `dp`를 만든다.

- 점화식 : `dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + cost[i][j]`

- `min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]})`를 출력한다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> cost(0, vector<int>(3));
vector<vector<int>> dp(0, vector<int>(3));

int main()
{
    cin >> n;
    cost = dp = vector<vector<int>>(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> cost[i][j];
        }
    }
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }
    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';

    return 0;
}
```
