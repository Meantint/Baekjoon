# BOJ_9465 - 스티커

&nbsp;`DP`를 이용하여 풀었다. 재채점 돼서 오답으로 바뀌었는데 기존의 코드에서는 `n`이 `1`인 경우 정답을 `0`으로 출력했기 때문에 틀렸었다(예상..이지만 거의 확실). 해당 이유를 처리해주는 코드를 추가 작성했다.

## 문제/코드 링크

- [BOJ_9465 - 스티커](https://www.acmicpc.net/problem/9465)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `vector<vector<int>>` 변수 `cost`와 `dp`를 만들었다.

- 점화식 : `dp[i][j] = max(dp[(i + 1) % 2][j - 2], dp[(i + 1) % 2][j - 1])`

- `dp` 값을 넣는 작업이 끝난 후 `max(dp[0][n - 1], dp[1][n - 1])`을 출력한다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int tc, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<vector<int>> cost, dp;
        cost.resize(2, vector<int>(n));
        dp.resize(2, vector<int>(n, 0));
        for (int r = 0; r < 2; ++r) {
            for (int c = 0; c < n; ++c) {
                cin >> cost[r][c];
            }
        }

        dp[0][0] = cost[0][0];
        dp[1][0] = cost[1][0];
        if (n < 2) {
            cout << max(dp[0][0], dp[1][0]) << '\n';
            continue;
        }
        dp[0][1] = cost[1][0] + cost[0][1];
        dp[1][1] = cost[0][0] + cost[1][1];
        for (int c = 2; c < n; ++c) {
            dp[0][c] = max({dp[1][c - 2], dp[1][c - 1]}) + cost[0][c];
            dp[1][c] = max({dp[0][c - 2], dp[0][c - 1]}) + cost[1][c];
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }

    return 0;
}
```
