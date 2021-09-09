# BOJ_2206 - 벽 부수고 이동하기

&nbsp;

## 문제/코드 링크

- [BOJ_2206 - 벽 부수고 이동하기](https://www.acmicpc.net/problem/2206)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 일반 2차원 `isVisited`를 선언하는 경우 빠르게 갈려고 벽을 뚫은 케이스 때문에 실제 정답이 `isVisited`에 가로막혀 정답을 도출하지 못하는 경우가 있다.

  - 그렇기 때문에 `isVisited`에 벽을 뚫은 적이 있고 방문한 경우와 벽을 뚫은 적 없이 방문한 경우 두가지로 나눠서 방문 처리하면 정답을 도출해낼 수 있다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int n, m;
vector<vector<char>> board;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool isSafe(int y, int x)
{
    if (n <= y || y < 0 || m <= x || x < 0) {
        return false;
    }
    return true;
}

int BFS()
{
    int ret = -1;
    queue<tuple<int, int, int, bool>> q;
    vector<vector<vector<bool>>> isVisited(n, vector<vector<bool>>(m, vector<bool>(2, false)));

    q.push(make_tuple(0, 0, 0, true));
    isVisited[0][0][1] = true;
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int dist = get<2>(q.front());
        bool wall = get<3>(q.front());
        q.pop();

        if (y == n - 1 && x == m - 1) {
            return dist + 1;
        }

        for (int i = 0; i < 4; ++i) {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if (isSafe(cy, cx)) {
                if (board[cy][cx] == '1' && wall && !isVisited[cy][cx][0]) {
                    isVisited[cy][cx][0] = true;
                    q.push(make_tuple(cy, cx, dist + 1, false));
                }
                else if (board[cy][cx] == '0' && !isVisited[cy][cx][wall]) {
                    isVisited[cy][cx][wall] = true;
                    q.push(make_tuple(cy, cx, dist + 1, wall));
                }
            }
        }
    }

    return ret;
}

int main()
{
    cin >> n >> m;
    board = vector<vector<char>>(n, vector<char>(m));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> board[r][c];
        }
    }

    cout << BFS() << '\n';

    return 0;
}
```
