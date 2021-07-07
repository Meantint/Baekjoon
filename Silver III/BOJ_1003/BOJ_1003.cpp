#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int t, n;
vector<PII> dp(41);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[0] = make_pair(1, 0);
    dp[1] = make_pair(0, 1);
    for (int i = 2; i < 41; ++i) {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n].first << ' ' << dp[n].second << '\n';
    }

    return 0;
}