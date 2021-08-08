#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int c, n;
vector<pair<int, int>> info;
vector<int> dp;

int main()
{
    cin >> c >> n;
    info.resize(n);
    dp.resize(c + 1, -1);
    for (int i = 0; i < n; ++i) {
        cin >> info[i].first >> info[i].second;
    }

    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= c; ++j) {
            int index = j + info[i].second;
            if (index > c) {
                index = c;
            }
            if (dp[j] != -1) {
                if (dp[index] == -1) {
                    dp[index] = dp[j] + info[i].first;
                }
                else {
                    dp[index] = min(dp[index], dp[j] + info[i].first);
                }
            }
        }
    }
    cout << dp[c] << '\n';

    return 0;
}