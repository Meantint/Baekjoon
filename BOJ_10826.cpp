#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> dp(3);

string sum(string s1, string s2)
{
    string str = "";
    int ss1 = s1.size() - 1;
    int ss2 = s2.size() - s1.size();

    int carry = 0;
    while (ss1 >= 0) {
        // 자릿수가 넘어간다면
        int val = (s1[ss1] - '0') + (s2[ss1 + ss2] - '0') + carry;
        str += to_string(val % 10);
        carry = val / 10;
        --ss1;
    }
    --ss2;
    while (ss2 >= 0) {
        int val = s2[ss2] - '0' + carry;
        str += to_string(val % 10);
        carry = val / 10;
        --ss2;
    }
    if (carry == 1) {
        str += "1";
    }
    reverse(str.begin(), str.end());

    return str;
}

int main()
{
    cin >> n;
    dp[0] = "0";
    dp[1] = "1";

    for (int i = 2; i <= n; ++i) {
        dp[i % 3] = sum(dp[(i - 2) % 3], dp[(i - 1) % 3]);
    }
    cout << dp[n % 3] << '\n';

    return 0;
}