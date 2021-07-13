# BOJ_15681 - 트리와 쿼리

&nbsp;루트로 지정한 곳 부터 `dfs`를 통해 각각 위치의 서브트리 개수를 저장해놓으면 된다.

- Baekjoon - [트리와 쿼리](https://www.acmicpc.net/problem/15681)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 간선 정보를 저장하는 `vector<vector<int>>` 변수 `adj`를 선언했다.

- 각 노드를 루트로 했을 때의 서브트리에 속한 노드 개수를 저장하는 `vector<int>` 변수 `answer`를 선언했다.

- `dfs` 처리를 위한 `vector<bool>` 변수 `isVisited`를 선언했다.

- 함수 `dfs`

  - 현재 노드를 방문처리 해준다.

  - 현재 노드와 연결된 모든 인접 노드를 확인해서 아직 방문하지 않은 노드라면 루트로 했을 때의 서브트리 소속 노드이기 때문에 `dfs` 함수를 재귀호출해서 `answer[next_node]`의 값을 채워준 후 현재의 개수인 `answer[current_node]`에 더해준다.

    - `answer[i]` : `i` 노드를 정점으로 했을 때의 서브트리 노드의 개수

- 함수 `solve`에서 `dfs(r)`을 할 경우 `answer` 배열이 모두 채워지기 때문에 요구하는 쿼리의 답만 출력해주면 된다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
vector<vector<int>> adj;
vector<int> answer;
vector<bool> isVisited;

void dfs(int current_node)
{
    isVisited[current_node] = true;
    int current_size = adj[current_node].size();
    for (int i = 0; i < current_size; ++i) {
        int next_node = adj[current_node][i];
        if (!isVisited[next_node]) {
            dfs(next_node);
            answer[current_node] += answer[next_node];
        }
    }
}

void solve()
{
    dfs(r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> q;
    adj.resize(n);
    answer.resize(n, 1);
    isVisited.resize(n, false);

    for (int i = 1; i < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1 - 1].push_back(v2 - 1);
        adj[v2 - 1].push_back(v1 - 1);
    }
    --r;

    solve();

    for (int i = 0; i < q; ++i) {
        int start;
        cin >> start;
        cout << answer[start - 1] << '\n';
    }

    return 0;
}
```
