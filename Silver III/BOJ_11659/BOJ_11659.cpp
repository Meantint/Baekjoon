#include <iostream>
#include <vector>

using namespace std;

int n, m, i, j;
vector<int> num;
vector<int> prefix;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    num = vector<int>(n);
    prefix = vector<int>(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + num[i - 1];
    }
    while (m--) {
        cin >> i >> j;
        cout << prefix[j] - prefix[i - 1] << '\n';
    }

    return 0;
}