# BOJ_11726 - 2×n 타일링

&nbsp;`DP`를 이용해서 풀었다.

- Baekjoon - [2×n 타일링](https://www.acmicpc.net/problem/11726)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 점화식 : `dp[i] = (dp[i - 1] + dp[i - 2]) % 10007`

- `dp[n]`를 출력한다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dp;

int main()
{
    cin >> n;
    dp.resize(n + 1);

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
    cout << dp[n] << '\n';

    return 0;
}
```
