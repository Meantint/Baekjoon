#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
vector<vector<int>> adj;
vector<int> answer;
vector<bool> isVisited;

void dfs(int current_node)
{
    isVisited[current_node] = true;
    int current_size = adj[current_node].size();
    for (int i = 0; i < current_size; ++i) {
        int next_node = adj[current_node][i];
        if (!isVisited[next_node]) {
            dfs(next_node);
            answer[current_node] += answer[next_node];
        }
    }
}

void solve()
{
    dfs(r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> q;
    adj.resize(n);
    answer.resize(n, 1);
    isVisited.resize(n, false);

    for (int i = 1; i < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1 - 1].push_back(v2 - 1);
        adj[v2 - 1].push_back(v1 - 1);
    }
    --r;

    solve();

    for (int i = 0; i < q; ++i) {
        int start;
        cin >> start;
        cout << answer[start - 1] << '\n';
    }

    return 0;
}