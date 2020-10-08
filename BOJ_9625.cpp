#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int k;
vector<vector<int>> dp;

int main()
{
    cin >> k;
    dp = vector<vector<int>>(k + 1, vector<int>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i <= k; ++i) {
        vector<int> tmp = dp[i - 1];
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    }
    cout << dp[k][0] << ' ' << dp[k][1] << '\n';

    return 0;
}