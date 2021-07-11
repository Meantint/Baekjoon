#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int V, E;
vector<vector<PII>> adj;

vector<int> dijkstra(int start)
{
    vector<int> dist(V, 2112345678);
    dist[start] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        // 더 짧은 경로 있으면 볼 필요 x
        if (dist[here] < cost) continue;
        // 인접한 경로 모두 검사
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            // 더 짧은 경로 발견하면, dist[] 갱신, 우선순위 큐 삽입
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
    cin >> V >> E;
    adj.resize(V);

    for (int i = 0; i < E; ++i) {
        int st, ed, dist;
        cin >> st >> ed >> dist;

        adj[st - 1].push_back(make_pair(ed - 1, dist));
    }
    int start, end;
    cin >> start >> end;
    vector<int> answer = dijkstra(start - 1);
    // for (int i = 0; i < answer.size(); ++i) {
    //     if (answer[i] == 2112345678) {
    //         cout << "INF" << '\n';
    //         continue;
    //     }
    //     cout << answer[i] << '\n';
    // }
    cout << answer[end - 1] << '\n';

    return 0;
}