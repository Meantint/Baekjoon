#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#define PII pair<int, int>

using namespace std;

int m, n, answer = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<tuple<int, int, int>> q;
vector<vector<bool>> isVisited;
vector<vector<int>> prev, board;

bool isFull()
{
    for (auto& row : board) {
        for (auto& elem : row) {
            if (elem == 0) {
                return false;
            }
        }
    }

    return true;
}

void bfs()
{
    while (!q.empty()) {
        int time = get<0>(q.front());
        int cx = get<1>(q.front());
        int cy = get<2>(q.front());
        q.pop();

        // 이미 방문한 곳이라면
        if (isVisited[cx][cy]) {
            continue;
        }
        isVisited[cx][cy] = true;
        // 토마토 없는 칸이라면
        if (board[cx][cy] == -1 || board[cx][cy] == 1) {
            continue;
        }
        board[cx][cy] = 1;
        answer = (answer < time) ? time : answer;

        for (int i = 0; i < 4; ++i) {
            int ccx = cx + dx[i];
            int ccy = cy + dy[i];
            if (ccx < 0 || ccx >= n || ccy < 0 || ccy >= m) {
                continue;
            }
            q.push(make_tuple(time + 1, ccx, ccy));
        }
    }
}

int main()
{
    cin >> m >> n;

    isVisited = vector<vector<bool>>(n, vector<bool>(m, false));
    board = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 1) {
                q.push(make_tuple(0, i, j));
                board[i][j] = 0;
            }
        }
    }
    bfs();
    // 모든 토마토가 익었다면
    if (isFull()) {
        cout << answer << '\n';
    }
    else {
        cout << "-1" << '\n';
    }

    return 0;
}