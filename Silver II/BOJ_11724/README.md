# BOJ_11724 - 연결 요소의 개수

&nbsp;`BFS`를 이용하여 풀었다.

- Baekjoon - [연결 요소의 개수](https://www.acmicpc.net/problem/11724)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `isVisited[i]`가 `false`라면 아직 방문하지 않은 노드이므로 이 노드와 연결된 노드들을 전부 `true`로 바꿔준다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, answer = 0;
vector<bool> isVisited;
vector<vector<int>> adj;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // 이미 방문했다면
        if (isVisited[cur]) {
            continue;
        }
        isVisited[cur] = true;
        for (auto& next : adj[cur]) {
            q.push(next);
        }
    }
}

int main()
{
    cin >> n >> m;
    adj.resize(n);
    isVisited.resize(n, false);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1 - 1].push_back(v2 - 1);
        adj[v2 - 1].push_back(v1 - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (!isVisited[i]) {
            bfs(i);
            ++answer;
        }
    }
    cout << answer << '\n';

    return 0;
}
```
