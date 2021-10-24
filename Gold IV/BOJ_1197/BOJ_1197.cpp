#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

int answer = 0;

void prim()
{
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int startSize = adj[1].size();
    for (int i = 0; i < startSize; ++i) {
        int next = adj[1][i].first;
        int nextDist = adj[1][i].second;

        pq.push(make_pair(nextDist, next));
    }
    while (!pq.empty()) {
        int cur = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        // print test
        // cout << cur << ", " << curDist << '\n';

        // 아직 연결된 간선이 없으면
        if (parent[cur] != 1) {
            parent[cur] = 1;
            answer += curDist;
        }

        int size = adj[cur].size();
        for (int i = 0; i < size; ++i) {
            int next = adj[cur][i].first;
            int nextDist = adj[cur][i].second;

            // 아직 연결된 간선이 없을 때만 pq에 추가해준다.
            if (parent[next] != 1) {
                pq.push(make_pair(nextDist, next));
            }
        }
    }

    return;
}

int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;

        adj[v1].push_back(make_pair(v2, dist));
        adj[v2].push_back(make_pair(v1, dist));
    }
    prim();

    cout << answer << '\n';

    return 0;
}