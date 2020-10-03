// 범위 안낚이고 잘 품

#include <cstring>
#include <iostream>
#include <vector>

#define DIV 1000000007
#define ll long long

using namespace std;

int n;
vector<vector<ll>> dp(4, vector<ll>(2, 0));
vector<vector<ll>> tmp(4, vector<ll>(2, 0));

int main()
{
    tmp[0][1] = 1;

    cin >> n;
    while (n--) {
        dp[0][0] = (tmp[0][1] + tmp[1][0] + tmp[1][1]) % DIV;
        dp[0][1] = (tmp[0][0] + tmp[1][1]) % DIV;
        dp[1][0] = (tmp[0][0] + tmp[1][1] + tmp[2][0] + tmp[2][1]) % DIV;
        dp[1][1] = (tmp[0][0] + tmp[0][1] + tmp[1][0] + tmp[2][1]) % DIV;
        dp[2][0] = (tmp[1][0] + tmp[2][1] + tmp[3][0]) % DIV;
        dp[2][1] = (tmp[1][0] + tmp[1][1] + tmp[2][0] + tmp[3][1]) % DIV;
        dp[3][0] = (tmp[2][0] + tmp[3][1]) % DIV;
        dp[3][1] = (tmp[3][0] + tmp[2][1]) % DIV;
        tmp = dp;
    }
    cout << dp[0][1] << '\n';

    return 0;
}