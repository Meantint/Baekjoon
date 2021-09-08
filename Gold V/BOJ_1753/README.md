# BOJ_1753 - 최단경로

&nbsp;`Dijkstra`를 이용해 풀었다.

## 문제/코드 링크

- [BOJ_1753 - 최단경로](https://www.acmicpc.net/problem/1753)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `dijkstra(st - 1)`의 값을 `vector<int> minDist`에 넣어준다.

- 차례대로 출력해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 2112345678
#define PII pair<int, int>

using namespace std;

int v, e, st;
int v1, v2, d;
vector<vector<PII>> adj;

vector<int> dijkstra(int src)
{
    vector<int> dist(v, INF);

    dist[src] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) {
            continue;
        }
        for (auto& elem : adj[cur]) {
            int next = elem.first;
            int nextDist = cost + elem.second;

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
    cin >> v >> e >> st;
    adj.resize(v);
    for (int i = 0; i < e; ++i) {
        cin >> v1 >> v2 >> d;
        adj[v1 - 1].push_back(make_pair(v2 - 1, d));
    }
    vector<int> minDist = dijkstra(st - 1);
    for (auto& elem : minDist) {
        if (elem == 2112345678) {
            cout << "INF\n";
        }
        else {
            cout << elem << '\n';
        }
    }

    return 0;
}
```
