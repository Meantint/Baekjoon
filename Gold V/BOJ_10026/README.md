# BOJ_10026 - 적록색약

&nbsp;적록색약인 경우와 아닌 경우를 판별하는 `BFS`를 따로 만들면 된다.

## 문제/코드 링크

- [BOJ_10026 - 적록색약](https://www.acmicpc.net/problem/10026)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 적록색약이 아닌 사람을 처리하는 함수 `BFS_RGB`를 선언했다.

- 적록색약인 사람을 처리하는 함수 `BFS_RRB`를 선언했다.

- `BFS_RGB`의 경우 비교값이 동일할 때만 `queue`에 `push`해준다.

- `BFS_RRB`의 경우 현재 비교하려는 값 `compare`가 `B`가 아닌 경우 현재 방문한 `board[cy][cx]`가 `B`가 아닌 경우 `queue`에 `push` 해주고 `B`인 경우는 `board[cy][cx]`가 `B`인 경우 `queue`에 `push` 해주면 된다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n;
int ansRGB = 0, ansRRB = 0;
vector<vector<char>> board;
vector<vector<bool>> isVisitedRGB, isVisitedRRB;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool isSafe(int y, int x)
{
    if (n <= y || y < 0 || n <= x || x < 0) {
        return false;
    }
    return true;
}

void BFS_RGB(int r, int c)
{
    char compare = board[r][c];
    queue<pair<int, int>> q;

    q.push(make_pair(r, c));
    isVisitedRGB[r][c] = true;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if (isSafe(cy, cx) && board[cy][cx] == compare && !isVisitedRGB[cy][cx]) {
                q.push(make_pair(cy, cx));
                isVisitedRGB[cy][cx] = true;
            }
        }
    }
}

void BFS_RRB(int r, int c)
{
    char compare = board[r][c];
    bool isRG = (compare != 'B' ? true : false);
    queue<pair<int, int>> q;

    q.push(make_pair(r, c));
    isVisitedRRB[r][c] = true;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if (isSafe(cy, cx)) {
                if (isRG && board[cy][cx] != 'B' && !isVisitedRRB[cy][cx]) {
                    q.push(make_pair(cy, cx));
                    isVisitedRRB[cy][cx] = true;
                }
                else if (!isRG && board[cy][cx] == 'B' && !isVisitedRRB[cy][cx]) {
                    q.push(make_pair(cy, cx));
                    isVisitedRRB[cy][cx] = true;
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    board = vector<vector<char>>(n, vector<char>(n));
    isVisitedRGB = isVisitedRRB = vector<vector<bool>>(n, vector<bool>(n, false));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> board[r][c];
        }
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (!isVisitedRGB[r][c]) {
                BFS_RGB(r, c);
                ++ansRGB;
            }
            if (!isVisitedRRB[r][c]) {
                BFS_RRB(r, c);
                ++ansRRB;
            }
        }
    }
    cout << ansRGB << ' ' << ansRRB << '\n';

    return 0;
}
```
