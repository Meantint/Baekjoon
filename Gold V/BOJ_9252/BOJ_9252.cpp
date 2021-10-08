#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s1, s2;
vector<vector<pair<int, string>>> dp;

int main()
{
    cin >> s1 >> s2;

    int s1Size = s1.size() + 1;
    int s2Size = s2.size() + 1;
    dp.resize(s1Size, vector<pair<int, string>>(s2Size, make_pair(0, "")));
    for (int r = 1; r < s1Size; ++r) {
        for (int c = 1; c < s2Size; ++c) {
            if (s1[r - 1] == s2[c - 1]) {
                dp[r][c].first = dp[r - 1][c - 1].first + 1;
                dp[r][c].second = dp[r - 1][c - 1].second + s1[r - 1];
            }
            else {
                if (dp[r - 1][c].first >= dp[r][c - 1].first) {
                    dp[r][c].first = dp[r - 1][c].first;
                    dp[r][c].second = dp[r - 1][c].second;
                }
                else {
                    dp[r][c].first = dp[r][c - 1].first;
                    dp[r][c].second = dp[r][c - 1].second;
                }
            }
        }
    }
    cout << dp[s1Size - 1][s2Size - 1].first << '\n'
         << dp[s1Size - 1][s2Size - 1].second << '\n';

    return 0;
}