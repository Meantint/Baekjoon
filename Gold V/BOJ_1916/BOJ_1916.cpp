#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 2112345678
#define ll long long

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(int start)
{
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) {
            continue;
        }

        int size = adj[cur].size();
        for (int i = 0; i < size; ++i) {
            int nextCost = adj[cur][i].second + cost;
            int next = adj[cur][i].first;

            if (dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push(make_pair(nextCost, next));
            }
        }
    }

    return dist;
}

int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;

        adj[v1].push_back(make_pair(v2, dist));
        // adj[v2].push_back(make_pair(v1, dist));
    }

    int start, target;
    cin >> start >> target;

    vector<int> answer = dijkstra(start);
    // for (auto& a : answer) {
    //     cout << a << ' ';
    // }
    // cout << '\n';
    cout << answer[target] << '\n';

    return 0;
}