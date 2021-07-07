#include <iostream>
#include <vector>

#define DIV 1000000007

using namespace std;

int n;
vector<int> dp;

int main()
{
    cin >> n;
    dp.resize(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = (dp[i - 2] + dp[i - 1] + 1) % DIV;
    }
    cout << dp[n] << '\n';

    return 0;
}