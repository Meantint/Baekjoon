#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int V, E;
vector<vector<PII>> adj;
vector<int> parent;

vector<int> dijkstra(int start)
{
    vector<int> dist(V, 2112345678);
    parent = vector<int>(V, 0);
    for (int i = 0; i < V; ++i) {
        parent[i] = i;
    }
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
                parent[there] = here;
                dist[there] = nextDist;
                pq.push(make_pair(nextDist, there));
            }
        }
    }

    return dist;
}

void findPath(int cur, vector<int>& path)
{
    path.push_back(cur);
    if (parent[cur] == cur) {
        reverse(path.begin(), path.end());
        return;
    }
    findPath(parent[cur], path);
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
    cout << answer[end - 1] << '\n';
    vector<int> path;
    findPath(end - 1, path);
    cout << path.size() << '\n';
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] + 1 << ' ';
    }
    cout << '\n';

    return 0;
}