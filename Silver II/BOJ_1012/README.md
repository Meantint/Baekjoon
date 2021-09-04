# BOJ_1012 - 유기농 배추

&nbsp;`BFS`를 이용하여 풀었다.

## 문제/코드 링크

- [BOJ_1012 - 유기농 배추](https://www.acmicpc.net/problem/1012)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 함수 `bfs`의 형태가 `BFS`를 이용할 때 사용하는 기본적인 뼈대이므로 기억하고 있자.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int answer;
int n, m, k, t;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<bool>> board;

void bfs(int x, int y)
{
    queue<PII> q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (board[cx][cy] == false) {
            continue;
        }
        board[cx][cy] = false;

        for (int i = 0; i < 4; ++i) {
            int ccx = cx + dx[i];
            int ccy = cy + dy[i];
            // 배열 범위 벗어나면
            if (ccx < 0 || ccx >= n || ccy < 0 || ccy >= m) {
                continue;
            }
            // (ccx, ccy)가 배추라면 q에 넣어준다.
            if (board[ccx][ccy]) {
                q.push(make_pair(ccx, ccy));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        board = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            board[x][y] = true;
        }

        answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // 배추가 있다면 bfs 해줘서 상하좌우 인접한 배추들을 없애준다.
                if (board[i][j]) {
                    bfs(i, j);
                    ++answer;
                }
            }
        }
        cout << answer << '\n';
    }

    return 0;
}
```
