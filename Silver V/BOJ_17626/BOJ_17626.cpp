#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dp(50001, 2112345678);

void init()
{
    dp[0] = 0;
    for (int i = 1; i * i < 50001; ++i) {
        for (int j = 0; j < 50001; ++j) {
            if (j + i * i < 50001) {
                dp[j + i * i] = min(dp[j + i * i], dp[j] + 1);
            }
            else {
                break;
            }
        }
    }
}

int main()
{
    init();

    cin >> n;
    cout << dp[n] << '\n';

    return 0;
}