#include <iostream>
#include <vector>

using namespace std;

int n;
vector<long long> dp(4);

int main()
{
    cin >> n;
    dp[1] = dp[2] = dp[3] = 1;
    for (int i = 4; i <= n; ++i) {
        dp[i % 4] = dp[(i - 1) % 4] + dp[(i - 3) % 4];
    }
    cout << dp[n % 4] << '\n';

    return 0;
}