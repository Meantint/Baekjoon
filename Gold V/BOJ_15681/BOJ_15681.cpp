#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
vector<vector<int>> adj;
vector<int> dp;
vector<bool> isVisited;

int dfs(int cur)
{
    isVisited[cur] = true;
    dp[cur] = 1;

    int size = adj[cur].size();
    for (int i = 0; i < size; ++i) {
        int next = adj[cur][i];
        if (!isVisited[next]) {
            dp[cur] += dfs(next);
        }
    }

    return dp[cur];
}

int main()
{
    scanf("%d %d %d", &n, &r, &q);
    adj.resize(n + 1);
    dp.resize(n + 1, 0);
    isVisited.resize(n + 1, false);

    for (int i = 1; i < n; ++i) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    dfs(r);

    for (int i = 0; i < q; ++i) {
        int node;
        scanf("%d", &node);

        printf("%d\n", dp[node]);
    }

    return 0;
}