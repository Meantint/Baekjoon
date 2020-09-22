#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 2112345678
#define PII pair<int, int>

using namespace std;

int N, K, T, W;
vector<vector<int>> adj;
vector<int> time;
vector<int> dist, topo;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        adj.clear();
        time.clear();
        dist.clear();
        topo.clear();

        cin >> N >> K;

        adj.resize(N);
        time.resize(N);
        dist.resize(N);
        topo.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> time[i];
        }
        for (int i = 0; i < K; ++i) {
            int from, to;
            cin >> from >> to;
            adj[from - 1].push_back(to - 1);
            ++topo[to - 1];
        }

        // 승리 건물
        cin >> W;

        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (topo[i] == 0) {
                q.push(i);
                dist[i] = time[i];
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == W - 1) break;

            for (int i = 0; i < adj[cur].size(); ++i) {
                int next = adj[cur][i];
                if (--topo[next] == 0) {
                    q.push(next);
                }
                if (dist[next] < dist[cur] + time[next]) {
                    dist[next] = dist[cur] + time[next];
                }
            }
        }
        cout << dist[W - 1] << '\n';
    }

    return 0;
}