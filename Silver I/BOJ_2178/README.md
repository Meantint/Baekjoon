# BOJ_2178 - 미로 탐색

&nbsp;

## 문제/코드 링크

- [BOJ_2178 - 미로 탐색](https://www.acmicpc.net/problem/2178)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 가중치가 없는 최단거리를 구하는 문제이기 때문에 `BFS`를 이용하면 쉽게 풀 수 있다.

- 다음 탐색하려는 위치 `(cy, cx)`가 배열 범위 내이고 `board[cy][cx]`가 `true`이고 `!isVisited[cy][cx]`가 `true`라면 `queue`에 넣어준다.

## Code

```cpp
#include <iostream>
#include <queue>
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
    int ret = 0;
    vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
    queue<pair<int, int>> q;  // first : y * 100 + x, second : count

    q.push(make_pair(0, 1));
    isVisited[0][0] = true;
    while (!q.empty()) {
        int y = q.front().first / 100;
        int x = q.front().first % 100;
        int count = q.front().second;
        q.pop();

        if (y == n - 1 && x == m - 1) {
            ret = count;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if (isSafe(cy, cx) && board[cy][cx] != '0' && !isVisited[cy][cx]) {
                q.push(make_pair(cy * 100 + cx, count + 1));
                isVisited[cy][cx] = true;
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
