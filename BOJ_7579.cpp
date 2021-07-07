#include <bits/stdc++.h>

using namespace std;

int n, m;
int sum = 0;
int memory[100];
int cost[100];
int dp[10010];

int main()
{
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> memory[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = sum; j >= cost[i]; --j) {
            dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
        }
    }
    for (int i = 0; i <= sum; ++i) {
        if (dp[i] >= m) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}