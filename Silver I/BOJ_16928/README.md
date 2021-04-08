# BOJ_16928 - 뱀과 사다리 게임

&nbsp;큐를 이용하여 풀었다. 오랜만에 알고리즘 다시 한다. 그새 다 까먹어서 손에 잘 안익는다 ㅋㅋ

- Baekjoon - [뱀과 사다리 게임](https://www.acmicpc.net/problem/16928)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `dist` 배열의 값들을 `MAX`(2112345678)로 초기화 한다.

- 큐를 진행하면서 얻은 카운트 값이 현재의 `dist` 값보다 작다면 갱신해주고 큐에 넣어준다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

#define MAX 2112345678
#define PII pair<int, int>

using namespace std;

int n, m;
int answer = -1;
vector<int> v, dist;
vector<int> ladder, snake;

void solve()
{
    // (pos, dist);
    queue<PII> q;
    q.push(make_pair(1, 0));
    dist[1] = 1;

    while (!q.empty()) {
        PII cur = q.front();
        q.pop();

        if (cur.first == 100) {
            answer = cur.second;
            break;
        }
        for (int i = 1; i <= 6; ++i) {
            PII next = make_pair(cur.first + i, cur.second + 1);

            if (next.first > 100) {
                break;
            }
            // 사다리 중 하나라면
            if (ladder[next.first] != 0) {
                next.first = ladder[next.first];
            }
            // 뱀 중 하나라면
            else if (snake[next.first] != 0) {
                next.first = snake[next.first];
            }

            if (dist[next.first] > next.second) {
                dist[next.first] = next.second;
                q.push(next);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    v = vector<int>(101, 0);
    dist = vector<int>(101, MAX);
    ladder = vector<int>(101, 0);
    snake = vector<int>(101, 0);

    for (int i = 0; i < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        ladder[v1] = v2;
    }
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        snake[v1] = v2;
    }

    solve();

    cout << answer << '\n';

    return 0;
}
```
