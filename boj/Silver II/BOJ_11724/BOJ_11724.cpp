#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, answer = 0;
vector<bool> isVisited;
vector<vector<int>> adj;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // 이미 방문했다면
        if (isVisited[cur]) {
            continue;
        }
        isVisited[cur] = true;
        for (auto& next : adj[cur]) {
            q.push(next);
        }
    }
}

int main()
{
    cin >> n >> m;
    adj.resize(n);
    isVisited.resize(n, false);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1 - 1].push_back(v2 - 1);
        adj[v2 - 1].push_back(v1 - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (!isVisited[i]) {
            bfs(i);
            ++answer;
        }
    }
    cout << answer << '\n';

    return 0;
}