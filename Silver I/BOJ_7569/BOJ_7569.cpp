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