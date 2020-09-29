#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string dp[101][101];
int n, m;

int main()
{
    cin >> n >> m;

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = '1';
        for (int j = 1; j < i; ++j) {
            string s1 = dp[i - 1][j - 1];
            string s2 = dp[i - 1][j];
            string tmp = "";
            int s1_idx = s1.size() - 1;
            int s2_idx = s2.size() - 1;
            int on_1 = 0;

            while (s1_idx >= 0 && s2_idx >= 0) {
                int val = (s1[s1_idx] - '0') + (s2[s2_idx] - '0') + on_1;
                if (val >= 10) {
                    tmp = to_string(val % 10) + tmp;
                    on_1 = 1;
                }
                else {
                    tmp = to_string(val) + tmp;
                    on_1 = 0;
                }
                --s1_idx;
                --s2_idx;
            }
            while (s1_idx >= 0) {
                int val = (s1[s1_idx] - '0') + on_1;
                if (val >= 10) {
                    tmp = to_string(val % 10) + tmp;
                    on_1 = 1;
                }
                else {
                    tmp = to_string(val) + tmp;
                    on_1 = 0;
                }
                --s1_idx;
            }
            while (s2_idx >= 0) {
                int val = (s2[s2_idx] - '0') + on_1;
                if (val >= 10) {
                    tmp = to_string(val % 10) + tmp;
                    on_1 = 1;
                }
                else {
                    tmp = to_string(val) + tmp;
                    on_1 = 0;
                }
                --s2_idx;
            }
            if (on_1 == 1) {
                tmp = '1' + tmp;
            }
            dp[i][j] = tmp;
        }
        dp[i][i] = '1';
    }
    // for (int i = 1; i < 10; ++i) {
    //     for (int j = 0; j <= i; ++j) {
    //         cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << '\n';
    //     }
    // }
    cout << dp[n][m] << '\n';

    return 0;
}