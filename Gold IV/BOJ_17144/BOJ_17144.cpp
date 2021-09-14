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