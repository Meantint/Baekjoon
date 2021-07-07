#include <bits/stdc++.h>

using namespace std;

int t;
long long dp[64][10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 64; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i == 0) {
                dp[i][j] = 1;
            }
            else {
                for (int k = 0; k < j + 1; ++k) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
    }

    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int num;
        cin >> num;

        long long answer = 0;
        for (int i = 0; i < 10; ++i) {
            answer += dp[num - 1][i];
        }
        cout << answer << '\n';
    }

    return 0;
}