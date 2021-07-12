# BOJ_1005 - ACM Craft

&nbsp;위상 정렬을 이용하는 문제. 푼지 꽤 됐는데 이제야 정리한다. 당시에도 어려워서 꽤 긴 기간을 두고 풀었던 것 같다.

- Baekjoon - [ACM Craft](https://www.acmicpc.net/problem/1005)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 간선의 정보를 담아두는 방향 그래프 `vector<vector<int>>` 변수 `adj`를 선언했다.

- 건물 짓는 시간을 담아놓은 `vector<int>` 변수 `time`을 선언했다.

- 위상 정렬을 위해 `vector<int>` 변수 `topo`를 선언했고, queue 안에서 시간을 갱신해주기 위한 `vector<int>` 변수 `dist`를 선언했다.

- 위상 정렬의 순서대로 하기위해서 `topo[i] = 0`인 값들을 모두 queue에 넣어준다.

- 특정 노드가 queue에 들어가기 전까지 가장 오래 걸리는 시간으로 계속 갱신해주고 `topo[i] = 0`이 되면 queue에 넣어준다.

- `cur = W - 1`인 경우 목표하는 건물을 찾은 것이므로 탐색을 종료하고 시간이 담겨있는 `dist[W - 1]`를 리턴한다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 2112345678
#define PII pair<int, int>

using namespace std;

int N, K, T, W;
vector<vector<int>> adj;
vector<int> time;
vector<int> dist, topo;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        adj.clear();
        time.clear();
        dist.clear();
        topo.clear();

        cin >> N >> K;

        adj.resize(N);
        time.resize(N);
        dist.resize(N);
        topo.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> time[i];
        }
        for (int i = 0; i < K; ++i) {
            int from, to;
            cin >> from >> to;
            adj[from - 1].push_back(to - 1);
            ++topo[to - 1];
        }

        // 승리 건물
        cin >> W;

        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (topo[i] == 0) {
                q.push(i);
                dist[i] = time[i];
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == W - 1) break;

            for (int i = 0; i < adj[cur].size(); ++i) {
                int next = adj[cur][i];
                if (--topo[next] == 0) {
                    q.push(next);
                }
                if (dist[next] < dist[cur] + time[next]) {
                    dist[next] = dist[cur] + time[next];
                }
            }
        }
        cout << dist[W - 1] << '\n';
    }

    return 0;
}
```
