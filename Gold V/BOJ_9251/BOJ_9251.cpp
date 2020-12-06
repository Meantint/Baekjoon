#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int row, col;
string s1, s2;
vector<vector<int>> dp;

int main()
{
    cin >> s1 >> s2;
    row = s1.size() + 1;
    col = s2.size() + 1;
    dp = vector<vector<int>>(row, vector<int>(col, 0));
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[row - 1][col - 1] << '\n';

    return 0;
}