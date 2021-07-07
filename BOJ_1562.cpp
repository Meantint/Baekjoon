// 비트마스크 아이디어까지는 완벽, 하지만 dp 구현하는 공부가 더 필요함

#include <cmath>
#include <iostream>
#include <vector>

#define DIV 1000000000

using namespace std;

int n;
long long answer = 0;
vector<vector<long long>> dp(10, vector<long long>(1024, 0));

int main()
{
    cin >> n;
    // dp 초기화
    for (int i = 1; i < 10; ++i) {
        dp[i][(1 << i)] = 1;
    }
    for (int t = 1; t < n; ++t) {
        vector<vector<long long>> tmp(10, vector<long long>(1024, 0));
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 1024; ++j) {
                if (dp[i][j] == 0) continue;
                if (i + 1 < 10) {
                    tmp[i + 1][(j | (1 << (i + 1)))] = (tmp[i + 1][(j | (1 << (i + 1)))] + dp[i][j]) % DIV;
                    // if ((j | (1 << (i + 1))) == 1023) {
                    //     cout << i << ", " << j << ", " << tmp[i][j] << ", " << dp[i + 1][(j | (1 << (i + 1)))] << endl;
                    // }
                }
                if (i - 1 >= 0) {
                    tmp[i - 1][(j | (1 << (i - 1)))] = (tmp[i - 1][(j | (1 << (i - 1)))] + dp[i][j]) % DIV;
                    // if ((j | (1 << (i - 1))) == 1023) {
                    //     cout << i << ", " << j << ", " << tmp[i][j] << ", " << dp[i - 1][(j | (1 << (i - 1)))] << endl;
                    // }
                }
            }
        }
        dp = tmp;
        // for (int i = 0; i < 10; ++i) {
        //     answer += dp[i][1023];
        // }
    }
    for (int i = 0; i < 10; ++i) {
        answer += (long long)dp[i][1023];
        answer %= DIV;
    }
    cout << answer << '\n';

    return 0;
}