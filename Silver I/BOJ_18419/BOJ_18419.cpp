#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n;
vector<ll> dp;

int solve(int num)
{
    int ret = 0;

    while (num != 0) {
        ret += (num % 10);
        num /= 10;
    }

    return ret;
}

int main()
{
    cin >> n;
    dp.resize(n + 1, 1LL);
    for (int i = 1; i < n + 1; ++i) {
        int sum = solve(i);

        if (i + sum > n) {
            continue;
        }
        else {
            dp[i + sum] += dp[i];
        }
    }
    cout << dp[n] << '\n';

    return 0;
}