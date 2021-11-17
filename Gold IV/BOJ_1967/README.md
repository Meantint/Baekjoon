# BOJ_1967 - 트리의 지름

&nbsp;`Dijkstra` 알고리즘을 통해 풀었다. 애초에 가장 먼 거리를 만드는 점 두 개를 어떻게 찾는지 모르면 못 푼다..(필자의 경험으로는)

## 문제/코드 링크

- [BOJ_1967 - 트리의 지름](https://www.acmicpc.net/problem/1967)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 한 점에서의 다른 모든 점과의 최단 거리를 구해주는 함수 `dijkstra`를 만든다.

- 첫 번째 `dijkstra` 함수를 호출해서 `0`번 노드와 가장 먼 노드 `maxIdx`를 찾는다.

- 이후 두 번째 `dijkstra` 함수를 호출해서 `maxIdx`번 노드와 가장 거리가 먼 노드와의 거리를 저장한 후 출력해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>
#define INF 2112345678

using namespace std;

int n, v1, v2, d;
vector<vector<PII>> adj;

vector<int> dijkstra(int start)
{
    vector<int> dist(n, INF);

    dist[start] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) {
            continue;
        }
        for (auto& elem : adj[cur]) {
            int next = elem.first;
            int nextDist = elem.second + cost;

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
    cin >> n;
    adj.resize(n);
    for (int i = 1; i < n; ++i) {
        cin >> v1 >> v2 >> d;
        adj[v1 - 1].push_back(make_pair(v2 - 1, d));
        adj[v2 - 1].push_back(make_pair(v1 - 1, d));
    }

    vector<int> v = dijkstra(0);
    int maxDist = -1;
    int maxIdx = -1;
    for (int i = 0; i < v.size(); ++i) {
        if (maxDist < v[i]) {
            maxDist = v[i];
            maxIdx = i;
        }
    }
    v = dijkstra(maxIdx);
    maxDist = -1;
    for (int i = 0; i < v.size(); ++i) {
        if (maxDist < v[i]) {
            maxDist = v[i];
        }
    }
    cout << maxDist << '\n';

    return 0;
}
```
