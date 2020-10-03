#include <iostream>
#include <vector>

#define PII pair<int, int>
#define INF 2112345678

using namespace std;

int t;
int n, m, w;
vector<vector<PII>> adj;

// 음수 사이클이 있을 경우 텅 빈 배열을 반환
vector<int> bellmanFord(int cur)
{
    // 시작점을 제외한 모든 정점까지의 최단 거리 상한을 INF로 둔다.
    vector<int> upper(n, INF);
    upper[cur] = 0;
    bool updated;
    // V번 순회한다
    for (int iter = 0; iter < n; ++iter) {
        updated = false;
        for (int here = 0; here < n; ++here) {
            for (int i = 0; i < adj[here].size(); ++i) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                // (here, there) 간선을 따라 완화를 시도한다.
                if (upper[there] > upper[here] + cost) {
                    // 성공
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
        // 모든 간선에 대해 완화가 실패했을 경우 V-1번도 돌 필요 없이 바로 종료한다.
        if (!updated) break;
    }
    // V번째 순회에서도 완화가 성공했다면 음수 사이클이 있다.
    if (updated) upper.clear();
    return upper;
}

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> m >> w;
        adj = vector<vector<PII>>(n, vector<PII>(0));
        for (int i = 0; i < m; ++i) {
            int v1, v2, dist;
            cin >> v1 >> v2 >> dist;

            adj[v1 - 1].push_back(make_pair(v2 - 1, dist));
            adj[v2 - 1].push_back(make_pair(v1 - 1, dist));
        }
        for (int i = 0; i < w; ++i) {
            int st, ed, dist;
            cin >> st >> ed >> dist;

            adj[st - 1].push_back(make_pair(ed - 1, -dist));
        }
        if (bellmanFord(0).empty()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}