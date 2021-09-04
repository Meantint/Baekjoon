# BOJ_7576 - 토마토

&nbsp;`BFS`를 이용하여 풀었다.

## 문제/코드 링크

- [BOJ_7576 - 토마토](https://www.acmicpc.net/problem/7576)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- (몇일만에 익었는지, 토마토 x 좌표, 토마토 y 좌표)를 저장한 `queue<tuple<int, int, int>>` 변수 `q`를 만들었다.

- 함수 `bfs()`를 통해 인접한 토마토들을 모두 익을 토마토들로 바꿔주고 가장 오래 걸린 시간을 갱신해준다.

- 함수 `isFull()`을 통해 하나라도 익지 않은 토마토가 있다면 `false`를, 모두 익었다면 `true`를 리턴해준다.

- `isFull()`이 `true`라면 `answer`를 리턴해주고, `false`라면 `-1`을 리턴한다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#define PII pair<int, int>

using namespace std;

int m, n, answer = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<tuple<int, int, int>> q;
vector<vector<bool>> isVisited;
vector<vector<int>> prev, board;

bool isFull()
{
    for (auto& row : board) {
        for (auto& elem : row) {
            if (elem == 0) {
                return false;
            }
        }
    }

    return true;
}

void bfs()
{
    while (!q.empty()) {
        int time = get<0>(q.front());
        int cx = get<1>(q.front());
        int cy = get<2>(q.front());
        q.pop();

        // 이미 방문한 곳이라면
        if (isVisited[cx][cy]) {
            continue;
        }
        isVisited[cx][cy] = true;
        // 토마토 없는 칸이라면
        if (board[cx][cy] == -1 || board[cx][cy] == 1) {
            continue;
        }
        board[cx][cy] = 1;
        answer = (answer < time) ? time : answer;

        for (int i = 0; i < 4; ++i) {
            int ccx = cx + dx[i];
            int ccy = cy + dy[i];
            if (ccx < 0 || ccx >= n || ccy < 0 || ccy >= m) {
                continue;
            }
            q.push(make_tuple(time + 1, ccx, ccy));
        }
    }
}

int main()
{
    cin >> m >> n;

    isVisited = vector<vector<bool>>(n, vector<bool>(m, false));
    board = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 1) {
                q.push(make_tuple(0, i, j));
                board[i][j] = 0;
            }
        }
    }
    bfs();
    // 모든 토마토가 익었다면
    if (isFull()) {
        cout << answer << '\n';
    }
    else {
        cout << "-1" << '\n';
    }

    return 0;
}
```
