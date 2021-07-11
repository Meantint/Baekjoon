#include <bits/stdc++.h>

using namespace std;

int n;
int cost[40010];
vector<int> dp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    dp.push_back(0);
    for (int i = 1; i < n; ++i) {
        if (cost[i] > cost[dp.back()]) {
            dp.push_back(i);
            continue;
        }
        int idx = dp.size();
        bool isPush = true;
        while (--idx >= 0) {
            if (cost[i] < cost[dp[idx]]) {
                if (idx == 0) {
                    dp[0] = i;
                    break;
                }
                if (cost[i] > cost[dp[idx - 1]]) {
                    dp[idx] = i;
                    break;
                }
            }
        }
    }
    cout << dp.size() << '\n';

    return 0;
}