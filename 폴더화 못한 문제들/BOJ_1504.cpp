#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>
#define INF 2112345678

using namespace std;

int M, X;
int V;
vector<vector<PII>> adj;

vector<int> dijkstra(int start)
{
    vector<int> dist(V, INF);
    dist[start] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push(PII(0, start));

    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(PII(nextDist, there));
            }
        }
    }
    return dist;
}

int main()
{
    cin >> V >> M;
    adj.resize(V);

    for (int i = 0; i < M; ++i) {
        int st, ed, dist;
        cin >> st >> ed >> dist;

        adj[st - 1].push_back(PII(ed - 1, dist));
        adj[ed - 1].push_back(PII(st - 1, dist));
    }

    int n1, n2;
    cin >> n1 >> n2;
    vector<int> d0 = dijkstra(0);
    vector<int> d1 = dijkstra(n1 - 1);
    vector<int> d2 = dijkstra(n2 - 1);
    int dist1, dist2;
    dist1 = d0[n1 - 1] + d1[n2 - 1] + d2[V - 1];
    dist2 = d0[n2 - 1] + d2[n1 - 1] + d1[V - 1];
    if ((d0[n1 - 1] == INF || d1[n2 - 1] == INF || d2[V - 1] == INF) &&
        (d0[n2 - 1] == INF || d2[n1 - 1] == INF || d1[V - 1] == INF)) {
        cout << "-1" << '\n';
    }
    else
        cout << min(dist1, dist2) << '\n';

    return 0;
}