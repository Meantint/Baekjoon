# BOJ_1167 - 트리의 지름

&nbsp;

## 문제/코드 링크

- [BOJ_1167 - 트리의 지름](https://www.acmicpc.net/problem/1167)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 임의의 점에서 `dijkstra`를 한 번 실행 후 가장 먼 거리에서 다시 한 번 `dijkstra`를 실행해줬을 때의 최대 거리가 트리의 지름이다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

#define INF 2112345678

using namespace std;

int n;
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
            int next = adj[cur][i].first;
            int nextCost = adj[cur][i].second + cost;

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
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        int from, to, dist;
        cin >> from;
        cin >> to;
        while (to != -1) {
            cin >> dist;
            adj[from].push_back(make_pair(to, dist));
            cin >> to;
        }
    }

    vector<int> distInfo = dijkstra(1);
    int dSize = distInfo.size();
    int mxVal = 0, mxIdx = -1;
    for (int i = 1; i < dSize; ++i) {
        if (mxVal < distInfo[i]) {
            mxVal = distInfo[i];
            mxIdx = i;
        }
    }

    distInfo = dijkstra(mxIdx);
    for (int i = 1; i < dSize; ++i) {
        if (mxVal < distInfo[i]) {
            mxVal = distInfo[i];
        }
    }
    cout << mxVal << '\n';

    return 0;
}
```
