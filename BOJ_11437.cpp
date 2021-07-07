#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> parent, depth;
vector<bool> isCheck;

int lca(int v1, int v2)
{
    while (depth[v1] < depth[v2]) {
        v2 = parent[v2];
    }
    while (depth[v1] > depth[v2]) {
        v1 = parent[v1];
    }

    while (v1 != v2) {
        v1 = parent[v1];
        v2 = parent[v2];
    }

    return v1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    adj.resize(n);
    depth.resize(n, -1);
    parent.resize(n, -1);
    isCheck.resize(n, false);

    for (int i = 0; i < n - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1 - 1].push_back(v2 - 1);
        adj[v2 - 1].push_back(v1 - 1);
    }

    queue<int> q;
    q.push(0);
    depth[0] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < adj[cur].size(); ++i) {
            int next = adj[cur][i];
            if (isCheck[next]) continue;

            parent[next] = cur;
            depth[next] = depth[cur] + 1;
            q.push(next);
        }
        isCheck[cur] = true;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        cout << lca(v1 - 1, v2 - 1) + 1 << '\n';
    }

    return 0;
}