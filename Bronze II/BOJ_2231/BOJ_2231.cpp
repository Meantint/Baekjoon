#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<int> dp(1000001, 0);

int main()
{
    cin >> n;

    for (int i = 1000000; i > 0; --i) {
        int ret = i;
        string str = to_string(i);
        for (auto ch : str) {
            ret += (ch - '0');
        }

        if (ret <= 1000000) {
            dp[ret] = i;
        }
    }
    cout << dp[n] << '\n';

    return 0;
}