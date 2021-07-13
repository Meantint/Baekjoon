# BOJ_9372 - 상근이의 여행

&nbsp;가중치 없는 `prim` 알고리즘과 비슷하다.

- Baekjoon - [상근이의 여행](https://www.acmicpc.net/problem/9372)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 어디에서 출발해도 간선의 개수는 `n - 1`개로 동일하다.

  - 아니 그러면 `queue` 쓸 필요도 없이 `n - 1` 출력하면 되는 것이었다. 정말로 `Minimal Spanning Tree`의 개념이기 때문에 별 생각하지 않아도 되는 문제였다.

  - 하지만 나는 그렇게 안 풀었기 때문에 설명하겠다.

- 방문하지 않은 노드인지를 `isVisited` 함수로 판단하면서 방문하지 않았다면 `queue`에 넣어주면서 `++answer`를 실행해준다. while문이 종료되었을 때 최소의 간선으로 각각의 노드를 한 번씩 방문하였고, 그렇기 때문에 `answer`에는 정답이 담겨있다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int tc, answer;
int n, m;
vector<vector<int>> adj;
vector<bool> isVisited;

void solve()
{
    answer = 0;

    queue<int> q;
    q.push(0);
    isVisited[0] = true;

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        for (auto next : adj[current_node]) {
            if (isVisited[next]) {
                continue;
            }

            ++answer;
            q.push(next);
            isVisited[next] = true;
        }
    }
}

int main()
{
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        cin >> n >> m;

        adj = vector<vector<int>>(n);
        isVisited = vector<bool>(n, false);
        for (int i = 0; i < m; ++i) {
            int v1, v2;
            cin >> v1 >> v2;

            adj[v1 - 1].push_back(v2 - 1);
            adj[v2 - 1].push_back(v1 - 1);
        }

        solve();

        cout << answer << '\n';
    }

    return 0;
}
```
