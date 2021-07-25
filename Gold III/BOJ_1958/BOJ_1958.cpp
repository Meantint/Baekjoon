#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s1, s2, s3;

int main()
{
    cin >> s1 >> s2 >> s3;

    int s1_size = s1.size();
    int s2_size = s2.size();
    int s3_size = s3.size();
    vector<vector<vector<int>>> dp(s1_size, vector<vector<int>>(s2_size, vector<int>(s3_size, 0)));

    for (int i = 0; i < s1_size; ++i) {
        for (int j = 0; j < s2_size; ++j) {
            for (int k = 0; k < s3_size; ++k) {
                if (s1[i] == s2[j] && s1[i] == s3[k]) {
                    if (0 < i && 0 < j && 0 < k) {
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    }
                    else {
                        dp[i][j][k] = 1;
                    }
                }
                else {
                    if (0 < i && dp[i][j][k] < dp[i - 1][j][k]) {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                    if (0 < j && dp[i][j][k] < dp[i][j - 1][k]) {
                        dp[i][j][k] = dp[i][j - 1][k];
                    }
                    if (0 < k && dp[i][j][k] < dp[i][j][k - 1]) {
                        dp[i][j][k] = dp[i][j][k - 1];
                    }
                }
            }
        }
    }

    cout << dp[s1_size - 1][s2_size - 1][s3_size - 1] << '\n';

    return 0;
}