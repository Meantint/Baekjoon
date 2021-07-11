#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        int cost[n];
        int dp[n][n];
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; ++i) {
                cin >> cost[i];
        }
        for (int i = 0; i < n; ++i) {
                dp[i][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
                for (int j = 0; j < n - i; ++j) {
                        int k = j + i;
                        if (cost[j] == cost[k]) {
                                if (j + 1 >= k - 1)
                                        dp[j][k] = 1;
                                else
                                        dp[j][k] = dp[j + 1][k - 1];
                        }
                        else
                                dp[j][k] = 0;
                }
        }

        cin >> m;
        for (int tc = 0; tc < m; ++tc) {
                int i, j;
                cin >> i >> j;
                cout << dp[i - 1][j - 1] << '\n';
        }

        return 0;
}
