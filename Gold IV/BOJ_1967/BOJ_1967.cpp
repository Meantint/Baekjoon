#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>
#define INF 2112345678

using namespace std;

int n, v1, v2, d;
vector<vector<PII>> adj;

vector<int> dijkstra(int start)
{
    vector<int> dist(n, INF);

    dist[start] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) {
            continue;
        }
        for (auto& elem : adj[cur]) {
            int next = elem.first;
            int nextDist = elem.second + cost;

            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push(make_pair(-nextDist, next));
            }
        }
    }
    return dist;
}

int main()
{
    cin >> n;
    adj.resize(n);
    for (int i = 1; i < n; ++i) {
        cin >> v1 >> v2 >> d;
        adj[v1 - 1].push_back(make_pair(v2 - 1, d));
        adj[v2 - 1].push_back(make_pair(v1 - 1, d));
    }

    vector<int> v = dijkstra(0);
    int maxDist = -1;
    int maxIdx = -1;
    for (int i = 0; i < v.size(); ++i) {
        if (maxDist < v[i]) {
            maxDist = v[i];
            maxIdx = i;
        }
    }
    v = dijkstra(maxIdx);
    maxDist = -1;
    for (int i = 0; i < v.size(); ++i) {
        if (maxDist < v[i]) {
            maxDist = v[i];
        }
    }
    cout << maxDist << '\n';

    return 0;
}