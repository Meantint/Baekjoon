#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int R, C;
    cin >> C >> R;

    vector<vector<char>> tmp(R, vector<char>(C, 0));
    vector<vector<int>> board(R, vector<int>(C, 0));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> tmp[i][j];
            board[i][j] = tmp[i][j] - '0';
        }
    }
    // pq.first : dist, pq.second : position
    priority_queue<pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> pq;
    vector<vector<bool>> isVisited(R, vector<bool>(C, false));
    pq.push(pair<int, PII>(0, PII(0, 0)));

    // cout << pq.top().first << pq.top().second.first << pq.top().second.second << endl;
    while (!pq.empty()) {
        int dist = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if (isVisited[x][y]) continue;
        if (x == R - 1 && y == C - 1) {
            cout << dist << '\n';

            return 0;
        }
        // cout << "x : " << x << ", y : " << y << ", dist : " << dist << endl;
        for (int i = 0; i < 4; ++i) {
            // 범위를 벗어나면
            if (x + dx[i] < 0 || x + dx[i] >= R || y + dy[i] < 0 || y + dy[i] >= C) continue;
            if (board[x + dx[i]][y + dy[i]] == 0) {
                pq.push(pair<int, PII>(dist, PII(x + dx[i], y + dy[i])));
            }
            else {
                pq.push(pair<int, PII>(dist + 1, PII(x + dx[i], y + dy[i])));
            }
        }
        isVisited[x][y] = true;
    }

    return 0;
}