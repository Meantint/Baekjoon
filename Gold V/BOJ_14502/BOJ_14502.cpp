#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int answer = 0;
vector<pair<int, int>> info;
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

int BFS(vector<vector<int>> temp)
{
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (temp[r][c] == 2) {
                q.push(make_pair(r, c));
                isVisited[r][c] = true;
            }
        }
    }
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if (isSafe(cy, cx) && temp[cy][cx] == 0 && !isVisited[cy][cx]) {
                temp[cy][cx] = 2;
                isVisited[cy][cx] = true;
                q.push(make_pair(cy, cx));
            }
        }
    }

    int ret = 0;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (temp[r][c] == 0) {
                ++ret;
            }
        }
    }

    return ret;
}

void solve()
{
    vector<int> comb(info.size(), 0);
    for (int i = 0; i < 3; ++i) {
        comb[info.size() - 1 - i] = 1;
    }

    do {
        for (int i = 0; i < info.size(); ++i) {
            if (comb[i]) {
                board[info[i].first][info[i].second] = 1;
            }
        }
        // vector<vector<int>> temp ;
        int res = BFS(board);
        if (answer < res) {
            answer = res;
        }
        for (int i = 0; i < info.size(); ++i) {
            if (comb[i]) {
                board[info[i].first][info[i].second] = 0;
            }
        }
    } while (next_permutation(comb.begin(), comb.end()));
}

int main()
{
    cin >> n >> m;
    board.resize(n, vector<int>(m));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> board[r][c];
            if (board[r][c] == 0) {
                info.push_back(make_pair(r, c));
            }
        }
    }

    solve();

    cout << answer << '\n';

    return 0;
}