#include <cmath>
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, m, t;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<PII> pos;
vector<vector<int>> board;

bool inRange(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m) return false;

    return true;
}

void simul()
{
    vector<vector<int>> tmp = board;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (tmp[i][j] < 5) {
                continue;
            }
            int size = (int)(tmp[i][j] / 5);
            for (int t = 0; t < 4; ++t) {
                int cx = i + dx[t];
                int cy = j + dy[t];
                if (inRange(cx, cy)) {
                    if (tmp[cx][cy] == -1) continue;
                    board[cx][cy] += size;
                    board[i][j] -= size;
                }
            }
        }
    }
    for (int i = pos[0].first - 1; i > 0; --i) {
        board[i][0] = board[i - 1][0];
    }
    for (int i = 0; i < m - 1; ++i) {
        board[0][i] = board[0][i + 1];
    }
    for (int i = 0; i < pos[0].first; ++i) {
        board[i][m - 1] = board[i + 1][m - 1];
    }
    for (int i = m - 1; i > 1; --i) {
        board[pos[0].first][i] = board[pos[0].first][i - 1];
    }
    board[pos[0].first][pos[0].second + 1] = 0;
    for (int i = pos[1].first + 1; i < n - 1; ++i) {
        board[i][0] = board[i + 1][0];
    }
    for (int i = 0; i < m - 1; ++i) {
        board[n - 1][i] = board[n - 1][i + 1];
    }
    for (int i = n - 1; i > pos[1].first; --i) {
        board[i][m - 1] = board[i - 1][m - 1];
    }
    for (int i = m - 1; i > 1; --i) {
        board[pos[1].first][i] = board[pos[1].first][i - 1];
    }
    board[pos[1].first][pos[1].second + 1] = 0;
}

int main()
{
    cin >> n >> m >> t;
    board = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == -1) {
                pos.push_back(make_pair(i, j));
            }
        }
    }
    while (t--) {
        simul();
    }
    int answer = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            answer += board[i][j];
        }
    }
    cout << answer << '\n';
    // cout << '\n';
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}