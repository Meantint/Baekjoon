#include <bits/stdc++.h>

using namespace std;

string str1, str2;

int main()
{
    cin >> str1 >> str2;

    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    int row = dp.size();
    int col = dp[0].size();
    int answer = 0;
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                answer = max(answer, dp[i][j]);
            }
        }
    }
    cout << answer << '\n';

    return 0;
}