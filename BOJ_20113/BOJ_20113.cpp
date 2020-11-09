#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define pii pair<int, int>

using namespace std;

int n, k;
vector<pii> dp;

int main()
{
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        dp.push_back(make_pair(0, i));
    }
    dp[0].first = -2000;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        ++dp[k].first;
    }
    sort(dp.begin(), dp.end(), greater<pii>());
    // 공동 두 명 이상 생겼다면
    if (dp[0].first == dp[1].first) {
        cout << "skipped\n";
    }
    else {
        cout << dp[0].second << '\n';
    }

    return 0;
}