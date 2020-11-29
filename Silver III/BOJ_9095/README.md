# BOJ_9095 - 1, 2, 3 더하기

&nbsp;`DP`를 이용해 풀었다.

- Baekjoon - [1, 2, 3 더하기](https://www.acmicpc.net/problem/9095)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 점화식 : `dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3], i > 3`

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, t;
vector<int> dp(13, 0);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < dp.size(); ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
```
