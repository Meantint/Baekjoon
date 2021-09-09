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