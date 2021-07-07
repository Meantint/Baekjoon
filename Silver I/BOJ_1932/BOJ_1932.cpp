#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> cost, dp;

int main()
{
    cin >> n;
    dp = cost = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> cost[i][j];
        }
    }
    dp[0][0] = cost[0][0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + cost[i][0];
        dp[i][i] = dp[i - 1][i - 1] + cost[i][i];
        for (int j = 1; j < i; ++j) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + cost[i][j];
        }
    }
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        answer = max(answer, dp[n - 1][i]);
    }
    cout << answer << '\n';

    return 0;
}