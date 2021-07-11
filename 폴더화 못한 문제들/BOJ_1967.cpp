#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>
#define INF 2112345678

using namespace std;

int n;
vector<vector<PII>> adj;

vector<int> dijkstra(int start)
{
    vector<int> dist(n, INF);
    dist[start] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int nextDist = adj[here][i].second + cost;

            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(nextDist, there));
            }
        }
    }

    return dist;
}

int main()
{
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;

        adj[v1 - 1].push_back(make_pair(v2 - 1, dist));
        adj[v2 - 1].push_back(make_pair(v1 - 1, dist));
    }
    vector<int> midNum = dijkstra(0);
    int maxIdx = -1;
    int maxDist = -1;
    for (int i = 0; i < n; ++i) {
        if (maxDist < midNum[i]) {
            maxDist = midNum[i];
            maxIdx = i;
        }
    }
    vector<int> answer = dijkstra(maxIdx);
    maxDist = -1;
    for (int i = 0; i < n; ++i) {
        maxDist = max(maxDist, answer[i]);
    }
    cout << maxDist << '\n';

    return 0;
}