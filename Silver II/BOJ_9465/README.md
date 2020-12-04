# BOJ_9465 - 스티커

&nbsp;`DP`를 이용하여 풀었다.

- Baekjoon - [스티커](https://www.acmicpc.net/problem/9465)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `vector<vector<int>>` 변수 `cost`와 `dp`를 만들었다.

- 점화식 : `dp[i][j] = max(dp[i][j - 2], dp[(i + 1) % 2][j - 2], dp[(i + 1) % 2][j - 1])`

- `dp` 값을 넣는 작업이 끝난 후 `max(dp[0][n - 1], dp[1][n - 1])`을 출력한다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int t, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> cost(2, vector<int>(n));
        vector<vector<int>> dp(2, vector<int>(n));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> cost[i][j];
            }
        }
        if (n == 1) {
            cout << max(dp[0][0], dp[1][0]) << '\n';
            continue;
        }
        dp[0][0] = cost[0][0];
        dp[1][0] = cost[1][0];
        dp[0][1] = cost[1][0] + cost[0][1];
        dp[1][1] = cost[0][0] + cost[1][1];
        for (int i = 2; i < n; ++i) {
            dp[0][i] = max({dp[0][i - 2], dp[1][i - 2], dp[1][i - 1]}) + cost[0][i];
            dp[1][i] = max({dp[1][i - 2], dp[0][i - 2], dp[0][i - 1]}) + cost[1][i];
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }
}
```
