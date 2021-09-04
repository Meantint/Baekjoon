#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> cost;
vector<vector<int>> dp;

int main()
{
    cin >> n;
    cost.resize(n);
    dp = vector<vector<int>>(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    if (n < 3) {  // exception
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            answer += cost[i];
        }
        cout << answer << '\n';

        return 0;
    }

    dp[0][0] = cost[0];
    dp[1][0] = cost[1];
    dp[1][1] = cost[0] + cost[1];
    for (int i = 2; i < n; ++i) {
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + cost[i];
        dp[i][1] = dp[i - 1][0] + cost[i];
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';

    return 0;
}