#include <iostream>
#include <vector>

#define MOD 10007

using namespace std;

int n;
vector<int> dp(1001, 0);

void init()
{
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i < 1001; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] * 2;
        dp[i] %= MOD;
    }
}

int main()
{
    init();

    cin >> n;
    cout << dp[n] << '\n';

    return 0;
}