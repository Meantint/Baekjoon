#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int answer = 2112345678;
vector<vector<int>> cost;
vector<vector<int>> dp;

int main()
{
    cin >> n;
    cost = vector<vector<int>>(n, vector<int>(3, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> cost[i][j];
        }
    }
    for (int fix = 0; fix < 3; ++fix) {
        dp = vector<vector<int>>(n, vector<int>(3, 0));
        for (int j = 0; j < 3; ++j) {
            if (j == fix) {
                dp[0][j] = cost[0][j];
            }
            else {
                dp[0][j] = 2112345678;
            }
        }
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + cost[i][j];
            }
        }
        for (int j = 0; j < 3; ++j) {
            if (j == fix) continue;
            dp[n - 1][j] = min(dp[n - 2][(j + 1) % 3], dp[n - 2][(j + 2) % 3]) + cost[n - 1][j];
        }
        for (int i = 0; i < 3; ++i) {
            if (i == fix) continue;
            answer = min(answer, dp[n - 1][i]);
        }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < 3; ++j) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
    cout << answer << '\n';

    return 0;
}