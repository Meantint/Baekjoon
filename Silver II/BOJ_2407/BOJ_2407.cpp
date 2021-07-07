#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<vector<string>> dp(101, vector<string>(101, "0"));

string cal(string n1, string n2)
{
    string tmp = "";

    int size = n1.size() - n2.size();
    if (n1.size() > n2.size()) {
        for (int i = 0; i < size; ++i) {
            n2 = '0' + n2;
        }
    }
    else {
        size *= -1;
        for (int i = 0; i < size; ++i) {
            n1 = '0' + n1;
        }
    }
    bool carry = false;
    for (int i = n2.size() - 1; i >= 0; --i) {
        int num = (n1[i] - '0') + (n2[i] - '0');
        // 이전에 올림이 있었다면
        if (carry) {
            ++num;
            carry = false;
        }
        // 더한 것이 한자리 수라면
        if (num < 10) {
            tmp = (char)('0' + num) + tmp;
        }
        else {
            carry = true;
            tmp = (char)('0' + (num - 10)) + tmp;
        }
    }
    // 끝나고 올림이 남아있다면 추가해준다.
    if (carry) {
        tmp = '1' + tmp;
    }

    return tmp;
}

int main()
{
    dp[1][0] = dp[1][1] = "1";
    for (int i = 2; i < 101; ++i) {
        dp[i][0] = dp[i][i] = "1";
        for (int j = 1; j < i; ++j) {
            dp[i][j] = cal(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    cin >> n >> m;
    cout << dp[n][m] << '\n';

    return 0;
}