#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;

void solve(int num, vector<int> v)
{
    // 원하는 개수 만큼 방문했다면
    if (v.size() == m) {
        for (auto& elem : v) {
            cout << elem << ' ';
        }
        cout << '\n';

        return;
    }
    for (int i = num; i <= n; ++i) {
        v.push_back(i);
        solve(i, v);
        v.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        solve(i, {i});
    }

    return 0;
}