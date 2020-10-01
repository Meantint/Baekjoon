#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#define PII pair<int, int>
#define TIII tuple<int, int, int>
#define INF 2112345678

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
vector<vector<char>> board;
vector<vector<vector<bool>>> isVisited;

int main()
{
    cin >> n >> m;
    isVisited = vector<vector<vector<bool>>>(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    board = vector<vector<char>>(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    // pq.first : distance, pq.second : x * 1000 + y, pq.third : wall(1 : pos, 0 : impos)
    priority_queue<TIII, vector<TIII>, greater<TIII>> pq;
    pq.push(make_tuple(1, 0, 1));

    while (!pq.empty()) {
        int cx = get<1>(pq.top()) / 1000;
        int cy = get<1>(pq.top()) % 1000;
        int dist = get<0>(pq.top());
        int isPos = get<2>(pq.top());
        pq.pop();

        if (cx == n - 1 && cy == m - 1) {
            cout << dist << '\n';

            return 0;
        }
        if (isVisited[cx][cy][isPos]) continue;
        // cout << "cx : " << cx << ", cy : " << cy << '\n';
        for (int i = 0; i < 4; ++i) {
            int ccx = cx + dx[i];
            int ccy = cy + dy[i];
            if (ccx < 0 || ccy < 0 || ccx >= n || ccy >= m) continue;
            if (board[ccx][ccy] == '1' && isPos) {
                pq.push(make_tuple(dist + 1, ccx * 1000 + ccy, 0));
            }
            else if (board[ccx][ccy] == '0') {
                pq.push(make_tuple(dist + 1, ccx * 1000 + ccy, isPos));
            }
        }
        if (isPos) {
            isVisited[cx][cy][0] = isVisited[cx][cy][1] = true;
        }
        else {
            isVisited[cx][cy][0] = true;
        }
    }
    cout << "-1\n";

    return 0;
}