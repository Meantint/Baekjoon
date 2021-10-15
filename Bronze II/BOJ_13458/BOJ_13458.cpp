#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n, b, c;
vector<int> info;
vector<ll> ans;

int main()
{
    cin >> n;
    info.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }
    cin >> b >> c;
    for (int i = 0; i < n; ++i) {
        info[i] -= b;
        if (info[i] > 0) {
            ans[i] = (info[i] - 1) / c + 1;
        }
    }

    ll answer = 0;
    for (int i = 0; i < n; ++i) {
        answer += ans[i];
    }
    answer += (ll)n;
    cout << answer << '\n';

    return 0;
}