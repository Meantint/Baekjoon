#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int f;
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    v.resize(n);
    for (auto& num : v) {
        cin >> num;
    }
    sort(v.begin(), v.end());
    cin >> m;
    while (m--) {
        cin >> f;
        cout << upper_bound(v.begin(), v.end(), f) - lower_bound(v.begin(), v.end(), f) << ' ';
    }

    return 0;
}