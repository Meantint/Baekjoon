# BOJ_9251 - LCS

&nbsp;`DP`를 이용해 풀었다.

- Baekjoon - [LCS](https://www.acmicpc.net/problem/9251)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 점화식

  - `dp[i][j] = dp[i - 1][j - 1] + 1`, `(s1[i] == s2[j])`

  - `dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])`, `(s1[i] != s2[j])`

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int row, col;
string s1, s2;
vector<vector<int>> dp;

int main()
{
    cin >> s1 >> s2;
    row = s1.size() + 1;
    col = s2.size() + 1;
    dp = vector<vector<int>>(row, vector<int>(col, 0));
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[row - 1][col - 1] << '\n';

    return 0;
}
```
