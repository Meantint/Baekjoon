#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> board;
vector<vector<bool>> isVisited;

void bfs()
{
    isVisited = vector<vector<bool>>(n, vector<bool>(m, false));

    queue<PII> q;
    q.push(make_pair(0, 0));
    isVisited[0][0] = true;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (board[cx][cy] == 1) continue;
        else {
            board[cx][cy] = 2;
        }
        for (int i = 0; i < 4; ++i) {
            int ccx = cx + dx[i];
            int ccy = cy + dy[i];
            if (ccx < 0 || ccy < 0 || ccx >= n || ccy >= m) continue;
            if (isVisited[ccx][ccy]) continue;
            q.push(make_pair(ccx, ccy));
            isVisited[ccx][ccy] = true;
        }
    }
}

bool isClear()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 1) return false;
        }
    }

    return true;
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

    int answer = 0;
    while (!isClear()) {
        // cout << "isGood\n";
        ++answer;
        bfs();
        // cout << "isGood\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] != 1) continue;
                int cnt = 0;
                for (int k = 0; k < 4; ++k) {
                    int cx = i + dx[k];
                    int cy = j + dy[k];

                    if (cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
                    if (board[cx][cy] == 2) ++cnt;
                }
                if (cnt > 1) board[i][j] = 0;
            }
        }
    }
    cout << answer << '\n';

    return 0;
}