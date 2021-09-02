# BOJ_2775 - 부녀회장이 될테야

&nbsp;`DP`로 풀었다.

## 문제/코드 링크

- [BOJ_2775 - 부녀회장이 될테야](https://www.acmicpc.net/problem/2775)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `dp[i][j] = dp[i - 1][j] + dp[i][j - 1]`

  - `dp[i - 1][j]` : 바로 아래층에 사는 사람의 수

  - `dp[i][j - 1]` : 바로 옆에 사는 사람의 수

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int tc, k, n;
vector<vector<int>> info(15, vector<int>(15, 0));

int main()
{
    for (int i = 1; i < 15; ++i) {
        info[0][i] = i;
    }
    for (int r = 1; r < 15; ++r) {
        for (int c = 1; c < 15; ++c) {
            info[r][c] = info[r - 1][c] + info[r][c - 1];
        }
    }

    cin >> tc;
    while (tc--) {
        cin >> k >> n;
        cout << info[k][n] << '\n';
    }

    return 0;
}
```
