#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int M, X;
int V;
vector<vector<PII>> adj;

vector<int> dijkstra(int start)
{
    vector<int> dist(V, 2112345678);
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
    cin >> V >> M >> X;
    adj.resize(V);

    for (int i = 0; i < M; ++i) {
        int st, ed, dist;
        cin >> st >> ed >> dist;

        adj[st - 1].push_back(PII(ed - 1, dist));
    }

    vector<int> distP(V, 0);
    // cout << "Good\n";
    vector<int> backHome = dijkstra(X - 1);
    for (int i = 0; i < V; ++i) {
        // cout << "Good\n";
        vector<int> tmp = dijkstra(i);
        distP[i] = tmp[X - 1] + backHome[i];
    }
    int maxTime = -1;
    for (int i = 0; i < distP.size(); ++i) {
        maxTime = max(maxTime, distP[i]);
    }
    cout << maxTime << '\n';

    return 0;
}