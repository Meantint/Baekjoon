#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int tc, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<vector<int>> cost, dp;
        cost.resize(2, vector<int>(n));
        dp.resize(2, vector<int>(n, 0));
        for (int r = 0; r < 2; ++r) {
            for (int c = 0; c < n; ++c) {
                cin >> cost[r][c];
            }
        }

        dp[0][0] = cost[0][0];
        dp[1][0] = cost[1][0];
        if (n < 2) {
            cout << max(dp[0][0], dp[1][0]) << '\n';
            continue;
        }
        dp[0][1] = cost[1][0] + cost[0][1];
        dp[1][1] = cost[0][0] + cost[1][1];
        for (int c = 2; c < n; ++c) {
            dp[0][c] = max({dp[1][c - 2], dp[1][c - 1]}) + cost[0][c];
            dp[1][c] = max({dp[0][c - 2], dp[0][c - 1]}) + cost[1][c];
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }

    return 0;
}