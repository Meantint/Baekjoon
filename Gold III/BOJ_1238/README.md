# BOJ_1238 - 파티

&nbsp;

## 문제/코드 링크

- [BOJ_1238 - 파티](https://www.acmicpc.net/problem/1238)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 단방향 그래프기 때문에 역방향 인접리스트 `rvAdj`를 만들고 반대 간선들의 정보를 넣어줬다.

- `adj`와 `rvAdj`를 `x`를 시작점으로 해서 `dijkstra`를 두 번 실행한다.

- `adj[i] + rvAdj[i]`가 가장 큰 값이 정답이다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

#define INF 2112345678

using namespace std;

int n, m, x;
vector<vector<pair<int, int>>> adj;
vector<vector<pair<int, int>>> rvAdj;

vector<int> dijkstra(vector<vector<pair<int, int>>> info, int start)
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

        int iSize = info[cur].size();
        for (int i = 0; i < iSize; ++i) {
            int nextCost = info[cur][i].second + cost;
            int next = info[cur][i].first;

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
    cin >> n >> m >> x;
    adj.resize(n + 1);
    rvAdj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;
        adj[v1].push_back(make_pair(v2, dist));
        rvAdj[v2].push_back(make_pair(v1, dist));
    }

    vector<int> info = dijkstra(adj, x);
    vector<int> rvInfo = dijkstra(rvAdj, x);

    int mxVal = 0;
    for (int i = 1; i <= n; ++i) {
        if (mxVal < info[i] + rvInfo[i]) {
            mxVal = info[i] + rvInfo[i];
        }
    }
    cout << mxVal << '\n';

    return 0;
}
```
