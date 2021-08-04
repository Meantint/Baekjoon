#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> board;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool isDivide()
{
    int ret = 0;
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            if (board[y][x] != 0 && !isVisited[y][x]) {
                if (ret == 1) {
                    return true;
                }
                ++ret;

                queue<pair<int, int>> q;
                q.push(make_pair(y, x));
                isVisited[y][x] = true;

                while (!q.empty()) {
                    int yy = q.front().first;
                    int xx = q.front().second;
                    q.pop();

                    for (int i = 0; i < 4; ++i) {
                        int cy = yy + dy[i];
                        int cx = xx + dx[i];

                        if (board[cy][cx] != 0 && !isVisited[cy][cx]) {
                            q.push(make_pair(cy, cx));
                            isVisited[cy][cx] = true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

bool isNone()
{
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            if (board[y][x] != 0) {
                return false;
            }
        }
    }

    return true;
}

int solve()
{
    int ret = 0;

    while (!isDivide()) {
        vector<vector<int>> delete_info(n, vector<int>(m, 0));

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; ++x) {
                if (board[y][x] != 0) {
                    for (int i = 0; i < 4; ++i) {
                        int cy = y + dy[i];
                        int cx = x + dx[i];

                        if (board[cy][cx] == 0) {
                            ++delete_info[y][x];
                        }
                    }
                }
            }
        }
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; ++x) {
                board[y][x] -= delete_info[y][x];
                if (board[y][x] < 0) {
                    board[y][x] = 0;
                }
            }
        }

        if (isNone()) {
            return 0;
        }

        ++ret;
    }

    return ret;
}

int main()
{
    cin >> n >> m;
    board = vector<vector<int>>(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << solve() << '\n';

    return 0;
}