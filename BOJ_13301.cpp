#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<long long> dp;
vector<long long> cost;

int main()
{
    cin >> n;
    dp.resize(81, 0);
    cost.resize(81, 0);
    dp[1] = 4;
    dp[2] = 6;
    if (n == 1 || n == 2) {
        cout << dp[n] << '\n';

        return 0;
    }
    cost[1] = cost[2] = 1;
    for (int i = 3; i <= n; ++i) {
        cost[i] = cost[i - 1] + cost[i - 2];
        dp[i] = dp[i - 1] + 2 * cost[i];
    }
    cout << dp[n] << '\n';

    return 0;
}