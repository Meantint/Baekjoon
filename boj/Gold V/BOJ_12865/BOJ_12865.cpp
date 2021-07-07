#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> w, v;
vector<int> dp;

int main()
{
    cin >> n >> k;
    w.resize(n);
    v.resize(n);
    dp.resize(k + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = k; j > 0; --j) {
            if (w[i] <= j) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[k] << '\n';

    return 0;
}