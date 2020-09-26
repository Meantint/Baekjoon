#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
    cin >> n;
    vector<int> v(n);
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    order = v;
    sort(order.begin(), order.end());
    order.erase(unique(order.begin(), order.end()), order.end());

    for (int i = 0; i < n; ++i) {
        cout << lower_bound(order.begin(), order.end(), v[i]) - order.begin() << ' ';
    }
    cout << '\n';
}