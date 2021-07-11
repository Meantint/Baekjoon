#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>
#define INF 2112345678

using namespace std;

int V;
vector<vector<int>> parent;
vector<vector<PII>> adj;
// vector<PII> banPath;

vector<int> dijkstra(int start)
{
    parent.resize(V);
    vector<int> dist(V, INF);
    dist[start] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        // 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을
        // 무시한다.
        if (dist[here] < cost) continue;
        // 인접한 정점들을 모두 검사한다.
        for (int i = 0; i < adj[here].size(); ++i) {
            // bool isBan = false;
            if (adj[here][i].second == -1) continue;
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            // 더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                parent[there].clear();
                parent[there].push_back(here);
                pq.push(make_pair(nextDist, there));
            }
            else if (dist[there] == nextDist) {
                parent[there].push_back(here);
            }
        }
    }

    return dist;
}

void findAndDel(int ed)
{
    queue<int> q;
    vector<bool> isVisited(V, false);
    q.push(ed);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (isVisited[cur]) continue;
        for (int x = 0; x < parent[cur].size(); ++x) {
            int prev = parent[cur][x];
            for (int i = 0; i < adj[prev].size(); ++i) {
                if (adj[prev][i].first == cur) {
                    adj[prev][i].second = -1;
                    break;
                }
            }
            q.push(prev);
        }
        isVisited[cur] = true;
    }
    return;
}

int main()
{
    // 최단 경로 값 저장
    cin >> V;
    adj.resize(V);

    int n;  // 간선 개수
    cin >> n;

    while (V != 0 || n != 0) {
        for (int i = 0; i < adj.size(); ++i) {
            adj[i].clear();
        }
        // 초기화
        adj.clear();
        parent.clear();
        adj.resize(V);
        parent.resize(V);

        int st, ed;
        cin >> st >> ed;
        for (int i = 0; i < n; ++i) {
            int a, b;
            int dist;
            cin >> a >> b >> dist;

            adj[a].push_back(make_pair(b, dist));
        }

        // 첫 번째 dijkstra에서 최단 경로를 구한다.
        dijkstra(st);
        // 최단 경로를 만드는 모든 path들을 비활성화 시킨다.
        findAndDel(ed);
        // 두 번째 dijkstra에서 거의 최단 경로를 구한다.
        int tmp = dijkstra(st)[ed];
        if (tmp == INF)
            cout << "-1" << '\n';
        else
            cout << tmp << '\n';

        cin >> V >> n;
    }

    return 0;
}