#include <bits/stdc++.h>

using namespace std;

int main()
{
        int T;
        cin >> T;

        for (int tc = 0; tc < T; ++tc) {
                int num;
                cin >> num;

                int dp[num][num];
                for (int i = 0; i < num; ++i) {
                        cin >> dp[i][i];
                }

                int line = 1;
                while (line != num) {
                        for (int i = 0; i < num - line; ++i) {
                                int j = i + line;
                                int minVal = 2000000000;
                                for (int k = i; k < j; ++k) {
                                        int tmp = dp[i][k] + dp[k + 1][j];
                                        if (i == k)
                                                tmp -= dp[i][k];
                                        if (j == k + 1)
                                                tmp -= dp[k + 1][j];
                                        minVal = min(minVal, tmp);
                                }
                                for (int k = i; k < j + 1; ++k) {
                                        minVal += dp[k][k];
                                }
                                dp[i][j] = minVal;
                        }
                        ++line;
                }
                cout << dp[0][num - 1] << '\n';
        }

        return 0;
}
