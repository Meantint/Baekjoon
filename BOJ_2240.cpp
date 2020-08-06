#include <bits/stdc++.h>

#define PII pair<int, int>

using namespace std;

int t, w;
int tree[1000];
int dp[1000][30];

int dfs(int cur, int move, int num)
{
    if (cur == t) {
        return 0;
    }
    if (move == w) {
        int cnt = 0;
        for (int i = cur; i < t; ++i) {
            if (tree[i] == num) {
                ++cnt;
            }
        }
        return cnt;
    }
    int& ret = dp[cur][move];
    if (ret != -1)
        return ret;
    ret = (tree[cur] == num) ? 1 : 0;
    // int cnt = 0;
    // for (int i = cur + 1; i < t; ++i) {
    //     if (tree[i] == num) {
    //         ++cnt;
    //     }
    // }
    int tmp = max({ dfs(cur + 1, move + 1, num % 2 + 1), dfs(cur + 1, move, num) /*, cnt */ });

    return (ret = ret + tmp);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> t >> w;
    for (int i = 0; i < t; ++i) {
        cin >> tree[i];
    }

    cout << max(dfs(0, 1, 2), dfs(0, 0, 1)) << '\n';
    // for (int i = 0; i < t; ++i) {
    //     for (int j = 0; j < w; ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}