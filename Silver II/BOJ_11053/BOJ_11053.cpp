#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;

vector<int> cost, dp;

int main()
{
    cin >> n;
    cost = dp = vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < i; ++j) {
            if (cost[j] < cost[i]) {
                if (cnt < dp[j]) {
                    cnt = dp[j];
                }
            }
        }
        dp[i] = cnt + 1;
    }
    for (auto& elem : dp) {
        answer = max(answer, elem);
    }
    cout << answer << '\n';

    return 0;
}