#include <bits/stdc++.h>

using namespace std;

int main()
{
        int n, m;
        int cc;
        cin >> n >> m >> cc;

        int x, y;
        if (cc != 0) {
                int cnt = 0;
                int map[n][m];
                bool isBreak = false;
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) {
                                map[i][j] = ++cnt;
                                if (map[i][j] == cc) {
                                        x = i;
                                        y = j;
                                        isBreak = true;
                                        break;
                                }
                        }
                        if (isBreak)
                                break;
                }
        }
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        if (cc != 0) {
                for (int i = 0; i <= x; ++i) {
                        for (int j = 0; j <= y; ++j) {
                                if (i == 0 || j == 0)
                                        dp[i][j] = 1;
                                else
                                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                        }
                }
                for (int i = x; i < n; ++i) {
                        for (int j = y; j < m; ++j) {
                                if (i == x || j == y)
                                        dp[i][j] = dp[x][y];
                                else
                                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                        }
                }
        }
        else {
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) {
                                if (i == 0 || j == 0)
                                        dp[i][j] = 1;
                                else
                                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                        }
                }
        }
        cout << dp[n - 1][m - 1] << '\n';

        return 0;
}
