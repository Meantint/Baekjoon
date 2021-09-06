#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<vector<int>> board;
vector<vector<int>> answer;

void BFS(int start)
{
    vector<bool> isVisited(n, false);
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (board[start][i] != 0) {
            // cout << "start " << start << " push " << i << '\n';
            q.push(i);
            isVisited[i] = true;
            answer[start][i] = 1;
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < n; ++i) {
            int next = board[cur][i];

            if (next != 0 && !isVisited[i]) {
                // cout << "start " << start << " push " << i << '\n';
                q.push(i);
                isVisited[i] = true;
                answer[start][i] = 1;
            }
        }
    }
}

int main()
{
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n));
    answer = vector<vector<int>>(n, vector<int>(n, 0));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> board[r][c];
        }
    }

    for (int r = 0; r < n; ++r) {
        BFS(r);
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << answer[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    return 0;
}