#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 2112345678

using namespace std;

int n, m;
int from, to;
vector<int> parent;
vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(int start)
{
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int cur = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if (dist[cur] < curDist) {
            continue;
        }

        int size = adj[cur].size();
        for (int i = 0; i < size; ++i) {
            int next = adj[cur][i].first;
            int nextDist = curDist + adj[cur][i].second;

            if (dist[next] > nextDist) {
                parent[next] = cur;
                dist[next] = nextDist;
                pq.push(make_pair(nextDist, next));
            }
        }
    }

    return dist;
}

int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    parent.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;

        adj[v1].push_back(make_pair(v2, dist));
    }
    cin >> from >> to;

    vector<int> answer = dijkstra(from);

    // find path
    vector<int> path(1, to);
    while (parent[path.back()] != path.back()) {
        path.push_back(parent[path.back()]);
    }
    reverse(path.begin(), path.end());

    cout << answer[to] << '\n';
    int pSize = path.size();
    cout << pSize << '\n';
    for (int i = 0; i < pSize; ++i) {
        cout << path[i] << ' ';
    }
    cout << '\n';

    return 0;
}