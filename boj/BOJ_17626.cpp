#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v(250);

int dfs(int val, int max_num, int t)
{
    if (t == 4) {
        return 100;
    }
    if (val == 0) {
        return 1;
    }
    int ans = 100;
    for (int i = max_num; i > 0; --i) {
        if (val < v[i]) continue;
        if (v[i] * 4 < val) break;
        ans = min(ans, dfs(val - v[i], i, t + 1));
    }
    return ans + 1;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < 250; ++i) {
        v[i] = i * i;
    }
    int cnt = 10;
    for (int i = 249; i > 0; --i) {
        if (n < v[i]) continue;
        if (v[i] * 4 < n) break;
        cnt = min(cnt, dfs(n - v[i], i, 0));
    }
    cout << cnt << '\n';

    return 0;
}