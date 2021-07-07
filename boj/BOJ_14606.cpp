#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
    vector<int> dp(11, 0);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i < 11; ++i) {
        dp[i] = dp[i - 1] + i - 1;
    }
    cin >> n;
    cout << dp[n] << '\n';

    return 0;
}