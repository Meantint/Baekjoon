#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int tc, answer;
int n, m;
vector<vector<int>> adj;
vector<bool> isVisited;

void solve()
{
    answer = 0;

    queue<int> q;
    q.push(0);
    isVisited[0] = true;

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        for (auto next : adj[current_node]) {
            if (isVisited[next]) {
                continue;
            }

            ++answer;
            q.push(next);
            isVisited[next] = true;
        }
    }
}

int main()
{
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        cin >> n >> m;

        adj = vector<vector<int>>(n);
        isVisited = vector<bool>(n, false);
        for (int i = 0; i < m; ++i) {
            int v1, v2;
            cin >> v1 >> v2;

            adj[v1 - 1].push_back(v2 - 1);
            adj[v2 - 1].push_back(v1 - 1);
        }

        solve();

        cout << answer << '\n';
    }

    return 0;
}