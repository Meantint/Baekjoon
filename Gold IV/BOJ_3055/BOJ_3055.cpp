#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n, m;
int ret = -1;
vector<vector<int>> water_info;
vector<vector<bool>> isVisited;
vector<string> board;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isSafe(int r, int c)
{
    if (r < 0 || n <= r || c < 0 || m <= c) {
        return false;
    }
    return true;
}

void solve()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == '*') {
                q.push(make_pair(50 * i + j, 0));
            }
            else if (board[i][j] == 'X') {
                water_info[i][j] = -1;
            }
            else if (board[i][j] == 'D') {
                water_info[i][j] = 2112345678;
            }
        }
    }
    while (!q.empty()) {
        int r = q.front().first / 50;
        int c = q.front().first % 50;
        int water = q.front().second;
        q.pop();

        // stone or already visited
        if (water_info[r][c] != 0) {
            continue;
        }

        water_info[r][c] = water;

        for (int i = 0; i < 4; ++i) {
            int cr = r + dr[i];
            int cc = c + dc[i];

            if (isSafe(cr, cc) && water_info[cr][cc] == 0) {
                q.push(make_pair(cr * 50 + cc, water + 1));
            }
        }
    }
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (board[r][c] == 'S') {
                q.push(make_pair(r * 50 + c, 0));
                break;
            }
        }
        if (!q.empty()) {
            break;
        }
    }
    while (!q.empty()) {
        int r = q.front().first / 50;
        int c = q.front().first % 50;
        int dist = q.front().second;
        q.pop();

        if (isVisited[r][c]) {
            continue;
        }
        isVisited[r][c] = true;

        if (dist >= water_info[r][c] && !(water_info[r][c] == 0)) {
            continue;
        }
        if (board[r][c] == 'D') {
            ret = dist;

            return;
        }

        for (int i = 0; i < 4; ++i) {
            int cr = r + dr[i];
            int cc = c + dc[i];

            if (isSafe(cr, cc) && !isVisited[cr][cc]) {
                q.push(make_pair(cr * 50 + cc, dist + 1));
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    water_info = vector<vector<int>>(n, vector<int>(m, 0));
    isVisited = vector<vector<bool>>(n, vector<bool>(m, false));
    board.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    solve();

    if (ret != -1) {
        cout << ret << '\n';
    }
    else {
        cout << "KAKTUS" << '\n';
    }

    return 0;
}