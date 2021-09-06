#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int tc;
vector<ll> dp(101, 0);

void init()
{
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    for (int i = 6; i <= 100; ++i) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    return;
}

int main()
{
    init();

    cin >> tc;
    while (tc--) {
        int num;
        cin >> num;

        cout << dp[num] << '\n';
    }

    return 0;
}