#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, b, c;
ll ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    cin >> b >> c;
    for (int i = 0; i < n; ++i) {
        p[i] -= b;
        ++ans;
        if (p[i] > 0) {
            ans += (ll)(p[i] / c);
            p[i] %= c;
            if (p[i] != 0) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}