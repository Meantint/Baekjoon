#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int t, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> cost(2, vector<int>(n));
        vector<vector<int>> dp(2, vector<int>(n));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> cost[i][j];
            }
        }
        if (n == 1) {
            cout << max(dp[0][0], dp[1][0]) << '\n';
            continue;
        }
        dp[0][0] = cost[0][0];
        dp[1][0] = cost[1][0];
        dp[0][1] = cost[1][0] + cost[0][1];
        dp[1][1] = cost[0][0] + cost[1][1];
        for (int i = 2; i < n; ++i) {
            dp[0][i] = max({dp[0][i - 2], dp[1][i - 2], dp[1][i - 1]}) + cost[0][i];
            dp[1][i] = max({dp[1][i - 2], dp[0][i - 2], dp[0][i - 1]}) + cost[1][i];
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }
}