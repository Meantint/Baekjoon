#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
    cin >> n;

    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 10;
    }
    cout << dp[n] << '\n';

    return 0;
}