# BOJ_2606 - 바이러스

&nbsp;`Graph`와 `BFS`로 풀었다.

## 문제/코드 링크

- [BOJ_2606 - 바이러스](https://www.acmicpc.net/problem/2606)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 간선 연결 정보를 담는 `vector<vector<int>>` 변수 `adj`를 만든다.

- `queue` 변수 `q`를 만들어 `0`번 인덱스(1번 컴퓨터)를 넣어준다.

- `1`번과 인접한 다른 간선들을 `q.push()` 해준다.

- `q.empty()`가 `true`가 될 때까지 while문을 반복한다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int v, m, answer = -1;
vector<bool> isVisited;
vector<vector<int>> adj;

void bfs(int start)
{
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (isVisited[cur]) {
            continue;
        }
        isVisited[cur] = true;
        ++answer;

        for (int i = 0; i < adj[cur].size(); ++i) {
            int next = adj[cur][i];
            q.push(next);
        }
    }
}

int main()
{
    cin >> v >> m;
    adj.resize(v);
    isVisited.resize(v, false);
    while (m--) {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1 - 1].push_back(v2 - 1);
        adj[v2 - 1].push_back(v1 - 1);
    }
    bfs(0);
    cout << answer << '\n';

    return 0;
}
```
