#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<double> num;
vector<double> dp;

int main()
{
    cin >> n;
    num.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    dp[0] = num[0];
    for (int i = 1; i < n; ++i) {
        if (dp[i - 1] > 1) {
            dp[i] = num[i] * dp[i - 1];
        }
        else {
            dp[i] = num[i];
        }
    }
    double answer = -1;
    for (int i = 0; i < n; ++i) {
        answer = max(answer, dp[i]);
    }
    cout << fixed;
    cout.precision(3);
    cout << answer << '\n';

    return 0;
}