#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
    cin >> n >> m;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    int overlap = 1;
    for (int i = 1; i <= n - m; ++i) {
        overlap *= i;
    }
    --overlap;
    int cnt = 0;
    do {
        if (cnt == overlap) {
            for (int i = 0; i < m; ++i) {
                cout << vec[i] << ' ';
            }
            cout << '\n';
            cnt = 0;
        }
        else {
            ++cnt;
        }
    } while (next_permutation(vec.begin(), vec.end()));

    return 0;
}