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
    int n, idx = 0;
    cin >> n;
    while (n != 0) {
        vector<vector<int>> board(n + 2, vector<int>(n + 2, -1));
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                cin >> board[i][j];
            }
        }
        priority_queue<pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> pq;
        vector<vector<bool>> isVisited(n + 2, vector<bool>(n + 2, false));
        pq.push(make_pair(0, PII(1, 1)));
        while (!pq.empty()) {
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (isVisited[x][y]) continue;
            if (x == n && y == n) {
                cout << "Problem " << ++idx << ": " << cost + board[x][y] << '\n';
                break;
            }
            for (int i = 0; i < 4; ++i) {
                if (board[x + dx[i]][y + dy[i]] != -1) {
                    pq.push(make_pair(cost + board[x][y], PII(x + dx[i], y + dy[i])));
                }
            }
            isVisited[x][y] = true;
        }
        cin >> n;
    }

    return 0;
}