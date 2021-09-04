#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<vector<char>> board;
vector<vector<bool>> isVisited;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool isSafe(int y, int x)
{
    if (n <= y || y < 0 || n <= x || x < 0) {
        return false;
    }
    return true;
}

int BFS(int r, int c)
{
    int ret = 0;
    queue<pair<int, int>> q;

    q.push(make_pair(r, c));
    isVisited[r][c] = true;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        ++ret;

        for (int i = 0; i < 4; ++i) {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if (isSafe(cy, cx) && board[cy][cx] == '1' && !isVisited[cy][cx]) {
                isVisited[cy][cx] = true;
                q.push(make_pair(cy, cx));
            }
        }
    }

    return ret;
}

int main()
{
    cin >> n;
    board = vector<vector<char>>(n, vector<char>(n));
    isVisited = vector<vector<bool>>(n, vector<bool>(n, false));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> board[r][c];
        }
    }

    vector<int> answer;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (board[r][c] == '1' && !isVisited[r][c]) {
                answer.push_back(BFS(r, c));
            }
        }
    }
    sort(answer.begin(), answer.end());

    int aSize = answer.size();
    cout << aSize << '\n';
    for (int i = 0; i < aSize; ++i) {
        cout << answer[i] << '\n';
    }

    return 0;
}