#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

int Prim()
{
    int ret = 0;
    int maxDist = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> isVisited(n + 1, false);

    int size = adj[1].size();
    for (int i = 0; i < size; ++i) {
        pair<int, int> next = adj[1][i];

        pq.push(make_pair(next.second, next.first));
    }
    isVisited[1] = true;
    while (!pq.empty()) {
        int cur = pq.top().second;
        int curCost = pq.top().first;
        pq.pop();

        if (isVisited[cur]) {
            continue;
        }
        isVisited[cur] = true;
        ret += curCost;
        if (maxDist < curCost) {
            maxDist = curCost;
        }

        size = adj[cur].size();
        for (int i = 0; i < size; ++i) {
            int next = adj[cur][i].first;
            int nextCost = adj[cur][i].second;

            if (!isVisited[next]) {
                pq.push(make_pair(nextCost, next));
            }
        }
    }

    return ret - maxDist;
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

    cout << Prim() << '\n';

    return 0;
}