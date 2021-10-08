# BOJ_9252 - LCS 2

&nbsp;[BOJ_9251 - LCS](https://www.acmicpc.net/problem/9251) 문제와 동일하게 `DP`로 풀었지만 각각의 원소에 현재까지 최대 길이의 문자열을 넣어두는 방식으로 풀었다. 가장 끝에서 부터 백트래킹으로 푸는 방식이 메모리적으로 더 효율적이다.

## 문제/코드 링크

- [BOJ_9252 - LCS 2](https://www.acmicpc.net/problem/9252)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 점화식

  - `dp[i][j].first = dp[i - 1][j - 1].first + 1`, `(s1[i] == s2[j])`

  - `dp[i][j].first = max(dp[i - 1][j].first, dp[i][j - 1].first)`, `(s1[i] != s2[j])`

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s1, s2;
vector<vector<pair<int, string>>> dp;

int main()
{
    cin >> s1 >> s2;

    int s1Size = s1.size() + 1;
    int s2Size = s2.size() + 1;
    dp.resize(s1Size, vector<pair<int, string>>(s2Size, make_pair(0, "")));
    for (int r = 1; r < s1Size; ++r) {
        for (int c = 1; c < s2Size; ++c) {
            if (s1[r - 1] == s2[c - 1]) {
                dp[r][c].first = dp[r - 1][c - 1].first + 1;
                dp[r][c].second = dp[r - 1][c - 1].second + s1[r - 1];
            }
            else {
                if (dp[r - 1][c].first >= dp[r][c - 1].first) {
                    dp[r][c].first = dp[r - 1][c].first;
                    dp[r][c].second = dp[r - 1][c].second;
                }
                else {
                    dp[r][c].first = dp[r][c - 1].first;
                    dp[r][c].second = dp[r][c - 1].second;
                }
            }
        }
    }
    cout << dp[s1Size - 1][s2Size - 1].first << '\n'
         << dp[s1Size - 1][s2Size - 1].second << '\n';

    return 0;
}
```
