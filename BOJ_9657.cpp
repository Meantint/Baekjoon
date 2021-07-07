#include <iostream>
#include <vector>

using namespace std;

int n;
// 상근이가 이기면 true, 창영이가 이기면 false
vector<bool> dp;

int main()
{
    cin >> n;
    dp.resize(n + 1, false);
    dp[1] = true;
    dp[3] = true;
    dp[4] = true;
    for (int i = 5; i <= n; ++i) {
        // dp[i - 1], dp[i - 3], dp[i - 4] 중에 한번이라도 지는 경우가 있으면 dp[i]는 무조건 이기는 경우(상근이 기준)가 있을 수 밖에 없다.
        if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4]) dp[i] = true;
    }
    if (dp[n]) {
        cout << "SK" << '\n';
    }
    else {
        cout << "CY" << '\n';
    }

    return 0;
}