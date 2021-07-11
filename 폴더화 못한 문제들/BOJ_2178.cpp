#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    cin >> n >> m;

    vector<vector<char>> board(n + 2, vector<char>(m + 2, '0'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i + 1][j + 1];
        }
    }
    priority_queue<pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> pq;
    vector<vector<bool>> isVisited(n + 2, vector<bool>(m + 2, false));
    pq.push(make_pair(1, make_pair(1, 1)));
    while (!pq.empty()) {
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        int dist = pq.top().first;
        pq.pop();

        if (cx == n && cy == m) {
            cout << dist << '\n';

            break;
        }
        // 벽이라면
        if (board[cx][cy] == '0') {
            continue;
        }
        // 방문한적이 있다면
        if (isVisited[cx][cy]) {
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            pq.push(make_pair(dist + 1, make_pair(cx + dx[i], cy + dy[i])));
        }
        isVisited[cx][cy] = true;
    }

    return 0;
}