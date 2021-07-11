#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dp(2000020, 0);

int main()
{
    // 1000010을 Fn(0), 1000011을 Fn(1)로 본다.
    dp[1000010] = 0;
    dp[1000011] = 1;

    for (int i = 1000009; i >= 0; --i) {
        dp[i] = dp[i + 2] - dp[i + 1];
        dp[i] %= 1000000000;
    }
    for (int i = 1000012; i < 2000020; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 1000000000;
    }

    cin >> n;
    if (dp[1000010 + n] > 0) {
        cout << '1' << '\n';
    }
    else if (dp[1000010 + n] == 0) {
        cout << '0' << '\n';
    }
    else {
        cout << "-1\n";
    }
    cout << abs(dp[1000010 + n]) << '\n';

    return 0;
}