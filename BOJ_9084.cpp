#include <bits/stdc++.h>

using namespace std;

int t, n, m;
int cost[20];
int dp[21][10010];

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> t;
        for (int tc = 0; tc < t; ++tc) {
                memset(cost, 0, sizeof(cost));
                memset(dp, 0, sizeof(dp));
                cin >> n;

                for (int i = 0; i < n; ++i) {
                        cin >> cost[i];
                }
                cin >> m;
                for (int i = 1; i <= n; ++i) {
                        for (int j = 1; j <= m; ++j) {
                                if (j % cost[i - 1] == 0)
                                        if (j - cost[i - 1] >= 0)
                                                dp[i][j] = dp[i][j - cost[i - 1]] + dp[i - 1][j];
                        }
                }
                for (int i = 1; i <= n; ++i) {
                        for (int j = 1; j <= m; ++j) {
                                cout << dp[i][j] << ' ';
                        }
                        cout << '\n';
                }
        }

        return 0;
}
