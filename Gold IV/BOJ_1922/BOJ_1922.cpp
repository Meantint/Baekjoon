#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

int solve()
{
    int ret = 0;
    int count = 1;

    vector<bool> isVisited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int cur_size = adj[0].size();
    for (int i = 0; i < cur_size; ++i) {
        pq.push(make_pair(adj[0][i].second, adj[0][i].first));
    }
    isVisited[0] = true;

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        if (isVisited[cur.second]) {
            continue;
        }
        isVisited[cur.second] = true;

        ret += cur.first;
        ++count;

        if (count == n) {
            return ret;
        }

        int cur_size = adj[cur.second].size();
        for (int i = 0; i < cur_size; ++i) {
            pair<int, int> next = adj[cur.second][i];

            if (isVisited[next.first]) {
                continue;
            }
            pq.push(make_pair(next.second, next.first));
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    adj.resize(n);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;

        adj[v1 - 1].push_back(make_pair(v2 - 1, dist));
        adj[v2 - 1].push_back(make_pair(v1 - 1, dist));
    }

    cout << solve() << '\n';

    return 0;
}