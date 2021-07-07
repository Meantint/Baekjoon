#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int v, m, answer = -1;
vector<bool> isVisited;
vector<vector<int>> adj;

void bfs(int start)
{
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (isVisited[cur]) {
            continue;
        }
        isVisited[cur] = true;
        ++answer;

        for (int i = 0; i < adj[cur].size(); ++i) {
            int next = adj[cur][i];
            q.push(next);
        }
    }
}

int main()
{
    cin >> v >> m;
    adj.resize(v);
    isVisited.resize(v, false);
    while (m--) {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1 - 1].push_back(v2 - 1);
        adj[v2 - 1].push_back(v1 - 1);
    }
    bfs(0);
    cout << answer << '\n';

    return 0;
}