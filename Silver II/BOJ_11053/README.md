# BOJ_11053 - 가장 긴 증가하는 부분 수열

&nbsp;`DP`를 이용하여 풀었다.

## 문제/코드 링크

- [BOJ_11053 - 가장 긴 증가하는 부분 수열](https://www.acmicpc.net/problem/11053)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `vector<int>` 변수 `cost`와 `dp`를 만든다.

- 값들을 `cost`에 입력한다.

- `cost[i]`가 `cost[j]` 보다 크고 수열의 크기 `cnt` 보다 `dp[j]`가 더 크다면 `cnt = dp[j]` 해준다.

- `for`문이 종료됐다면(안쪽) `dp[i] = cnt + 1` 해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;

vector<int> cost, dp;

int main()
{
    cin >> n;
    cost = dp = vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < i; ++j) {
            if (cost[j] < cost[i]) {
                if (cnt < dp[j]) {
                    cnt = dp[j];
                }
            }
        }
        dp[i] = cnt + 1;
    }
    for (auto& elem : dp) {
        answer = max(answer, elem);
    }
    cout << answer << '\n';

    return 0;
}
```
