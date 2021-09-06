# BOJ_17626 - Four Squares

&nbsp;처음에 `Backtracking` 문제라고 생각했는데 마지막 테스트케이스가 오래걸려서 뭐지..하다가 `DP`문제라는 것을 깨달았다.

## 문제/코드 링크

- [BOJ_17626 - Four Squares](https://www.acmicpc.net/problem/17626)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `dp[i]` : `i`를 만들 수 있는 최소 개수

- `dp[n + k * k] = min(dp[n + k * k], dp[n] + 1)`

  - `dp[n + k * k]` : 현재 들어있는 최솟값

  - `dp[n] + 1` : `n`에서 `k * k`를 더해서 만드는 경우의 값

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dp(50001, 2112345678);

void init()
{
    dp[0] = 0;
    for (int i = 1; i * i < 50001; ++i) {
        for (int j = 0; j < 50001; ++j) {
            if (j + i * i < 50001) {
                dp[j + i * i] = min(dp[j + i * i], dp[j] + 1);
            }
            else {
                break;
            }
        }
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
