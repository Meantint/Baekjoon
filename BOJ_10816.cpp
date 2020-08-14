#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<int> card(n);
    for (int i = 0; i < n; ++i) {
        cin >> card[i];
    }
    sort(card.begin(), card.end());

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        cout << upper_bound(card.begin(), card.end(), num) - lower_bound(card.begin(), card.end(), num) << ' ';
    }
    cout << '\n';

    return 0;
}