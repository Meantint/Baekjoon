# BOJ_1647 - 도시 분할 계획

## 문제/코드 링크

&nbsp;`Prim` 알고리즘을 이용해 풀었다.

- [BOJ_1647 - 도시 분할 계획](https://www.acmicpc.net/problem/1647)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 우선순위 큐를 이용하여 현재 집합에 포함되어 있는 노드들의 간선들을 길이가 짧은 순서로 출력되게 만들어준다.

- 다음을 리턴한다.

  - MST의 전체 길이 - 구축하고 있는 간선 중 가장 긴 간선의 길이

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

int Prim()
{
    int ret = 0;
    int maxDist = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> isVisited(n + 1, false);

    int size = adj[1].size();
    for (int i = 0; i < size; ++i) {
        pair<int, int> next = adj[1][i];

        pq.push(make_pair(next.second, next.first));
    }
    isVisited[1] = true;
    while (!pq.empty()) {
        int cur = pq.top().second;
        int curCost = pq.top().first;
        pq.pop();

        if (isVisited[cur]) {
            continue;
        }
        isVisited[cur] = true;
        ret += curCost;
        if (maxDist < curCost) {
            maxDist = curCost;
        }

        size = adj[cur].size();
        for (int i = 0; i < size; ++i) {
            int next = adj[cur][i].first;
            int nextCost = adj[cur][i].second;

            if (!isVisited[next]) {
                pq.push(make_pair(nextCost, next));
            }
        }
    }

    return ret - maxDist;
}

int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;

        adj[v1].push_back(make_pair(v2, dist));
        adj[v2].push_back(make_pair(v1, dist));
    }

    cout << Prim() << '\n';

    return 0;
}
```
