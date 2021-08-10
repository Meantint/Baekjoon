#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> adj;
vector<vector<int>> dp;

void dfs(int cur_node, vector<bool>& isVisited)
{
    isVisited[cur_node] = true;
    for (int i = 0; i < adj[cur_node].size(); ++i) {
        int next_node = adj[cur_node][i];

        if (!isVisited[next_node]) {
            dfs(next_node, isVisited);
            dp[cur_node][0] += dp[next_node][1];
            dp[cur_node][1] += (dp[next_node][0] < dp[next_node][1] ? dp[next_node][0] : dp[next_node][1]);
        }
    }

    return;
}

void solve()
{
    vector<bool> isVisited(n + 1, false);

    dfs(1, isVisited);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    adj.resize(n + 1);
    dp.resize(n + 1, {0, 1});
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    solve();
    cout << (dp[1][0] < dp[1][1] ? dp[1][0] : dp[1][1]) << '\n';

    return 0;
}