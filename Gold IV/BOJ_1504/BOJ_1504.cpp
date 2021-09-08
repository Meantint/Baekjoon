#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 2112345678
#define ll long long

using namespace std;

int n, e;
int t1, t2;
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
    cin >> n >> e;
    adj.resize(n + 1);
    for (int i = 0; i < e; ++i) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;
        adj[v1].push_back(make_pair(v2, dist));
        adj[v2].push_back(make_pair(v1, dist));
    }
    cin >> t1 >> t2;

    vector<int> info1 = dijkstra(t1);
    vector<int> info2 = dijkstra(t2);

    ll d1 = (ll)info1[1] + (ll)info1[t2] + (ll)info2[n];      // 1 -> t1 -> t2 -> n
    ll d2 = (ll)info1[1] + (ll)info1[t2] * 2 + (ll)info1[n];  // 1 -> t1 -> t2 -> t1 -> n
    ll d3 = (ll)info2[1] + (ll)info1[t2] + (ll)info1[n];      // 1 -> t2 -> t1 -> n
    ll d4 = (ll)info2[1] + (ll)info1[t2] * 2 + (ll)info2[n];  // 1 -> t2 -> t1 -> t2 -> n
    ll answer = min({d1, d2, d3, d4});
    if (answer >= INF) {
        cout << -1 << '\n';
    }
    else {
        cout << answer << '\n';
    }

    return 0;
}