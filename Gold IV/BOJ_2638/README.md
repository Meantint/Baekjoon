# BOJ_2638 - 치즈

&nbsp;완전 구현 문제

## 문제/코드 링크

- [BOJ_2638 - 치즈](https://www.acmicpc.net/problem/2638)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `Empty()`

  - 치즈가 하나라도 있다면 `false`, 하나도 없다면 `true`를 리턴하는 함수

- `UpdateOut()`

  - 외부 영역을 업데이트 해주는 함수

- `UpdateTarget()`

  - 이번 턴에 지워야 할 치즈를 업데이트 해주는 함수

- `Update()`

  - 지워야 할 치즈를 지워주는 과정을 처리해주는 함수

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> board;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool isSafe(int y, int x)
{
    if (n <= y || y < 0 || m <= x || x < 0) {
        return false;
    }
    return true;
}

bool Empty()
{
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (board[r][c]) {
                return false;
            }
        }
    }

    return true;
}

void UpdateOut(vector<vector<bool>>& isOut)
{
    queue<pair<int, int>> q;

    q.push(make_pair(0, 0));
    isOut[0][0] = true;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if (isSafe(cy, cx) && board[cy][cx] == 0 && !isOut[cy][cx]) {
                q.push(make_pair(cy, cx));
                isOut[cy][cx] = true;
            }
        }
    }
}

void UpdateTarget(const vector<vector<bool>> isOut, vector<vector<bool>>& isDel)
{
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (board[r][c] == 1) {
                int cnt = 0;
                for (int i = 0; i < 4; ++i) {
                    int y = r + dy[i];
                    int x = c + dx[i];

                    if (isSafe(y, x) && board[y][x] == 0 && isOut[y][x]) {
                        ++cnt;
                    }
                }

                if (cnt >= 2) {
                    isDel[r][c] = true;
                }
            }
        }
    }
}

void Update(const vector<vector<bool>> isDel)
{
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (isDel[r][c]) {
                board[r][c] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    board = vector<vector<int>>(n, vector<int>(m));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> board[r][c];
        }
    }

    int ret = 0;
    while (!Empty()) {
        ++ret;
        vector<vector<bool>> isDel(n, vector<bool>(m, false));
        vector<vector<bool>> isOut(n, vector<bool>(m, false));
        UpdateOut(isOut);            // 바깥 위치 업데이트
        UpdateTarget(isOut, isDel);  // 이번에 지울 타겟 업데이트
        Update(isDel);               // Update board
    }
    cout << ret << '\n';

    return 0;
}
```
