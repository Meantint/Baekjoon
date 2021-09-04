# BOJ_7569 - 토마토

&nbsp;

## 문제/코드 링크

- [BOJ_7569 - 토마토](https://www.acmicpc.net/problem/7569)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 최대 크기가 `100 * 100 * 100`이므로 배열로 만들어도 된다.

- `BFS` 함수에서 `board` 중 붙어 있는 토마토면 `board` 값을 직접 갱신해도 되므로 `isVisited` 함수가 따로 필요없었다.

- `queue`에 늦게 들어갈 수록 무조건 `cost`가 크기 때문에 반환 값 `ret`과 비교하면서 갱신하지 않고 그냥 갱신해도 된다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int m, n, h;
vector<vector<vector<int>>> board;
vector<vector<vector<bool>>> isVisited;

int dy[6] = {-1, 1, 0, 0, 0, 0};
int dx[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

bool isSafe(int y, int x, int z)
{
    if (n <= y || y < 0 || m <= x || x < 0 || h <= z || z < 0) {
        return false;
    }
    return true;
}

bool isFull()
{
    for (int k = 0; k < h; ++k) {
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (board[r][c][k] == 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

int BFS()
{
    int ret = 0;
    queue<tuple<int, int, int, int>> q;

    for (int k = 0; k < h; ++k) {
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (board[r][c][k] == 1) {
                    q.push(make_tuple(r, c, k, 0));
                    // isVisited[r][c][k] = true;
                }
            }
        }
    }
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int z = get<2>(q.front());
        int cost = get<3>(q.front());
        q.pop();

        ret = cost;

        for (int i = 0; i < 6; ++i) {
            int cy = y + dy[i];
            int cx = x + dx[i];
            int cz = z + dz[i];

            if (isSafe(cy, cx, cz) && board[cy][cx][cz] == 0 /* && !isVisited[cy][cx][cz] */) {
                q.push(make_tuple(cy, cx, cz, cost + 1));
                board[cy][cx][cz] = 1;
                // isVisited[cy][cx][cz] = true;
            }
        }
    }
    if (!isFull()) {
        ret = -1;
    }

    return ret;
}

int main()
{
    cin >> m >> n >> h;
    board = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(h)));
    isVisited = vector<vector<vector<bool>>>(n, vector<vector<bool>>(m, vector<bool>(h, false)));
    for (int k = 0; k < h; ++k) {
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                cin >> board[r][c][k];
            }
        }
    }

    cout << BFS() << '\n';

    return 0;
}
```
