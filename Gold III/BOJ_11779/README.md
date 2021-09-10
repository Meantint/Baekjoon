# BOJ_11779 - 최소비용 구하기 2

&nbsp;`Dijkstra`에 현재 노드의 부모 노드를 저장해주는 `parent` 배열을 만들어서 풀었다.

## 문제/코드 링크

- [BOJ_11779 - 최소비용 구하기 2](https://www.acmicpc.net/problem/11779)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `vector<int>` 타입 변수 `parent`를 선언했다.

  - `parent[i]` : `start`에서 `i`번 노드로 갈 때의 최단 경로에서 `i`번 노드 이전에 방문한 노드

- 역으로 `to`에서 `parent`를 찾아 올라가면 `from`이 나오게 된다. 그러므로 `from`이 나올 때까지 방문한 모든 노드들을 `path` 배열에 넣어주고 역순으로 저장되어 있으므로 역순으로 출력하거나 뒤집은 후 순차적으로 출력해주면 된다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 2112345678

using namespace std;

int n, m;
int from, to;
vector<int> parent;
vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(int start)
{
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int cur = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if (dist[cur] < curDist) {
            continue;
        }

        int size = adj[cur].size();
        for (int i = 0; i < size; ++i) {
            int next = adj[cur][i].first;
            int nextDist = curDist + adj[cur][i].second;

            if (dist[next] > nextDist) {
                parent[next] = cur;
                dist[next] = nextDist;
                pq.push(make_pair(nextDist, next));
            }
        }
    }

    return dist;
}

int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    parent.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;

        adj[v1].push_back(make_pair(v2, dist));
    }
    cin >> from >> to;

    vector<int> answer = dijkstra(from);

    // find path
    vector<int> path(1, to);
    while (parent[path.back()] != path.back()) {
        path.push_back(parent[path.back()]);
    }
    reverse(path.begin(), path.end());

    cout << answer[to] << '\n';
    int pSize = path.size();
    cout << pSize << '\n';
    for (int i = 0; i < pSize; ++i) {
        cout << path[i] << ' ';
    }
    cout << '\n';

    return 0;
}
```
