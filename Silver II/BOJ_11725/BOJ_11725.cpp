#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n;
int v1, v2;
vector<vector<int>> adj;
vector<int> answer;

void bfs(int start)
{
    vector<bool> isVisited(n, false);
    queue<PII> q;
    q.push(make_pair(0, -1));
    while (!q.empty()) {
        int cur = q.front().first;
        int parent = q.front().second;
        q.pop();

        if (isVisited[cur]) {
            continue;
        }
        isVisited[cur] = true;
        answer[cur] = parent;

        for (auto& elem : adj[cur]) {
            int next = elem;
            q.push(make_pair(next, cur));
        }
    }
}

int main()
{
    cin >> n;
    adj.resize(n);
    answer.resize(n);
    for (int i = 1; i < n; ++i) {
        cin >> v1 >> v2;
        adj[v1 - 1].push_back(v2 - 1);
        adj[v2 - 1].push_back(v1 - 1);
    }
    bfs(0);
    for (int i = 1; i < n; ++i) {
        cout << answer[i] + 1 << '\n';
    }

    return 0;
}