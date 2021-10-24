# BOJ_1197 - 최소 스패닝 트리

&nbsp;`Prim` 알고리즘을 이용해서 풀었다.

## 문제/코드 링크

- [BOJ_1197 - 최소 스패닝 트리](https://www.acmicpc.net/problem/1197)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 간선의 정보를 저장하는 `vector<vector<pair<int, int>>>` 타입 변수 `adj`를 선언했다.

- 최소 가중치를 연결하는 함수 `prim`을 선언했다.

  - 현재 간선이 연결되었는지의 유무를 나타내는 `vector<int>` 타입 변수 `parent`를 선언했다.

    - 굳이 `int` 타입으로 선언하지 않고 `isVisited`처럼 방문 배열 처리해도 문제 없이 풀 수 있다.

  - 간선들 중 가장 길이가 짧은 것부터 우선순위 큐에서 뽑아낸다.

  - 이미 간선이 연결된 지점이라면 `continue` 처리 해준다.

  - 연결되어있지 않은 간선이라면 `answer`에 `curDist`를 추가해주고 `parent`에 방문 처리를 해준다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

int answer = 0;

void prim()
{
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int startSize = adj[1].size();
    for (int i = 0; i < startSize; ++i) {
        int next = adj[1][i].first;
        int nextDist = adj[1][i].second;

        pq.push(make_pair(nextDist, next));
    }
    while (!pq.empty()) {
        int cur = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        // print test
        // cout << cur << ", " << curDist << '\n';

        // 아직 연결된 간선이 없으면
        if (parent[cur] != 1) {
            parent[cur] = 1;
            answer += curDist;
        }

        int size = adj[cur].size();
        for (int i = 0; i < size; ++i) {
            int next = adj[cur][i].first;
            int nextDist = adj[cur][i].second;

            // 아직 연결된 간선이 없을 때만 pq에 추가해준다.
            if (parent[next] != 1) {
                pq.push(make_pair(nextDist, next));
            }
        }
    }

    return;
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
    prim();

    cout << answer << '\n';

    return 0;
}
```
