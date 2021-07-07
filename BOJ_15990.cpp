#include <iostream>
#include <vector>

#define DIV 1000000009

using namespace std;

int n, t;
// dp[i][j] = 값 i를 j + 1을 마지막으로 써서 만들수 있는 모든 경우의 수
vector<vector<long long>> dp(100001, vector<long long>(3, 0));

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1][0] = dp[2][1] = dp[3][2] = dp[3][0] = dp[3][1] = 1;
    for (int i = 4; i < 100001; ++i) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % DIV;
        dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % DIV;
        dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % DIV;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (dp[n][0] + dp[n][1] + dp[n][2]) % DIV << '\n';
    }

    return 0;
}