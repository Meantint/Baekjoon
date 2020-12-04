# BOJ_11725 - 트리의 부모 찾기

&nbsp;인접 간선을 이용하여 풀었다.

- Baekjoon - [트리의 부모 찾기](https://www.acmicpc.net/problem/11725)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `(현재 위치, 이전 위치(부모))` 값을 담는 `queue<pair<int, int>>` 변수 `q`를 만든다.

- 어떤 노드의 인접 간선들의 부모에 `cur`를 포함해서 `q.push()` 해준다.

- `answer`에 담겨있는 부모의 번호가 `0`번 부터 시작하므로 `+1`해서 출력해준다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n;
int v1, v2;
vector<vector<int>> adj;
vector<int> answer;

void bfs(int start)
{
    vector<bool> isVisited(n, false);
    queue<PII> q;
    q.push(make_pair(0, -1));
    while (!q.empty()) {
        int cur = q.front().first;
        int parent = q.front().second;
        q.pop();

        if (isVisited[cur]) {
            continue;
        }
        isVisited[cur] = true;
        answer[cur] = parent;

        for (auto& elem : adj[cur]) {
            int next = elem;
            q.push(make_pair(next, cur));
        }
    }
}

int main()
{
    cin >> n;
    adj.resize(n);
    answer.resize(n);
    for (int i = 1; i < n; ++i) {
        cin >> v1 >> v2;
        adj[v1 - 1].push_back(v2 - 1);
        adj[v2 - 1].push_back(v1 - 1);
    }
    bfs(0);
    for (int i = 1; i < n; ++i) {
        cout << answer[i] + 1 << '\n';
    }

    return 0;
}
```
