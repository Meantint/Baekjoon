# BOJ_17144 - 미세먼지 안녕!

&nbsp;구현만 할 줄 알면 되는 문제. 그래서 좀 더 까다로울 수도 있다.

## 문제/코드 링크

- [BOJ_17144 - 미세먼지 안녕!](https://www.acmicpc.net/problem/17144)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `isSafe` : 배열 범위 체크

- `UpdateDust` : 각각의 위치에 업데이트 해줘야 할 먼지의 양을 `dust`에 저장해주는 함수

- `UpdateBoard` : `dust` 배열을 가지고 `board`를 업데이트 해주는 함수

- `MoveDust` : 공기청정기 규칙에 따라 먼지를 이동시키는 함수

- `PrintDust` : 테스트용 현재 `board` 배열 출력해주는 함수

- `DustSize` : `board`에 들어있는 모든 먼지의 양을 출력해주는 함수

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, m, tc;
vector<vector<int>> board;

vector<pair<int, int>> pos;  // 공기청정기 위, 아래 위치

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool isSafe(int y, int x)
{
    if (n <= y || y < 0 || m <= x || x < 0) {
        return false;
    }
    return true;
}

void UpdateBoard(vector<vector<int>> dust)
{
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            board[r][c] += dust[r][c];
        }
    }
}

void UpdateDust()
{
    vector<vector<int>> dust(n, vector<int>(m, 0));

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (board[r][c] <= 0) {
                continue;
            }
            int cnt = 0;
            int moveVal = board[r][c] / 5;
            for (int i = 0; i < 4; ++i) {
                int cy = r + dy[i];
                int cx = c + dx[i];

                if (isSafe(cy, cx) && board[cy][cx] != -1) {
                    dust[cy][cx] += moveVal;
                    ++cnt;
                }
            }
            dust[r][c] -= (cnt * moveVal);
        }
    }

    UpdateBoard(dust);
}

void MoveDust()
{
    pair<int, int> up = pos[0];
    pair<int, int> down = pos[1];

    // up
    int dir = 3;
    int prevVal = 0;
    pair<int, int> curPos = up;
    while (dir >= 0) {
        curPos.first -= dy[dir];
        curPos.second -= dx[dir];
        while (isSafe(curPos.first, curPos.second) && curPos != up) {
            int curVal = board[curPos.first][curPos.second];
            board[curPos.first][curPos.second] = prevVal;
            prevVal = curVal;

            curPos.first -= dy[dir];
            curPos.second -= dx[dir];
        }
        curPos.first += dy[dir];
        curPos.second += dx[dir];
        --dir;
    }
    // down
    vector<int> visitOrder = {1, 2, 3, 0};
    prevVal = 0;
    curPos = down;
    for (int i = 0; i < 4; ++i) {
        curPos.first += dy[visitOrder[i]];
        curPos.second += dx[visitOrder[i]];
        while (isSafe(curPos.first, curPos.second) && curPos != down) {
            int curVal = board[curPos.first][curPos.second];
            board[curPos.first][curPos.second] = prevVal;
            prevVal = curVal;

            curPos.first += dy[visitOrder[i]];
            curPos.second += dx[visitOrder[i]];
        }
        curPos.first -= dy[visitOrder[i]];
        curPos.second -= dx[visitOrder[i]];
    }
}

void PrintDust()
{
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cout << board[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int DustSize()
{
    int ret = 2;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            ret += board[r][c];
        }
    }

    return ret;
}

int main()
{
    cin >> n >> m >> tc;
    board.resize(n, vector<int>(m));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> board[r][c];
            if (board[r][c] == -1) {
                pos.push_back(make_pair(r, c));
            }
        }
    }

    // PrintDust();  // test
    while (tc--) {
        UpdateDust();
        // PrintDust();  // test
        MoveDust();
        // PrintDust();  // test
    }
    cout << DustSize() << '\n';

    return 0;
}
```
