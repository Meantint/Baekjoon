#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int r, c, w;
vector<vector<ll>> dp(30, vector<ll>(30, 1));

int main()
{
    cin >> r >> c >> w;
    for (int i = 1; i < 30; ++i) {
        for (int j = 1; j < i; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    ll answer = 0;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j <= i; ++j) {
            // cout << dp[r - 1 + i][c - 1 + j] << '\n';
            answer += dp[r - 1 + i][c - 1 + j];
        }
    }
    cout << answer << '\n';

    return 0;
}