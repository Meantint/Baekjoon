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