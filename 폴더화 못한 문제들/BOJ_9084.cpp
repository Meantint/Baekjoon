#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int cost[20];
int dp[10010];

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
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (j + cost[i] <= m)
                    dp[j + cost[i]] += dp[j];
            }
        }
        /*
        for (int i = 0; i <= m; ++i) {
            cout << dp[i] << ' ';
        }
        */
        cout << dp[m] << '\n';
    }

    return 0;
}