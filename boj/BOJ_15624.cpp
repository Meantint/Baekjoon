#include <iostream>
#include <vector>

#define DIV 1000000007

using namespace std;

int n;
vector<int> dp(3);

int main()
{
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i % 3] = (dp[(i + 1) % 3] + dp[(i + 2) % 3]) % DIV;
    }
    cout << dp[n % 3] << '\n';

    return 0;
}