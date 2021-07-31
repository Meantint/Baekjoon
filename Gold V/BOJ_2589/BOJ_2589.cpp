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
    if (y < 0 || n <= y || x < 0 || m <= x) {
        return false;
    }
    return true;
}

int solve()
{
    int ret = 0;
    // vector<vector<bool>> isVisited(n, vector<bool>(m, false));

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            if (board[y][x] == 'L') {
                pair<int, int> pos = make_pair(y, x);
                int temp = 0;

                vector<vector<bool>> mini_isVisited(n, vector<bool>(m, false));
                queue<pair<int, int>> q;

                q.push(make_pair(y * 50 + x, 0));
                mini_isVisited[y][x] = true;

                while (!q.empty()) {
                    int yy = q.front().first / 50;
                    int xx = q.front().first % 50;
                    int dist = q.front().second;
                    q.pop();

                    if (temp < dist) {
                        temp = dist;
                        pos = make_pair(yy, xx);
                    }

                    for (int i = 0; i < 4; ++i) {
                        int cy = yy + dy[i];
                        int cx = xx + dx[i];

                        if (isSafe(cy, cx) && board[cy][cx] == 'L' && !mini_isVisited[cy][cx]) {
                            q.push(make_pair(cy * 50 + cx, dist + 1));
                            mini_isVisited[cy][cx] = true;
                        }
                    }
                }

                if (ret < temp) {
                    ret = temp;
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

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            cin >> board[y][x];
        }
    }

    cout << solve() << '\n';

    return 0;
}