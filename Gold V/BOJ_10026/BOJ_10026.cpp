#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n;
int ansRGB = 0, ansRRB = 0;
vector<vector<char>> board;
vector<vector<bool>> isVisitedRGB, isVisitedRRB;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool isSafe(int y, int x)
{
    if (n <= y || y < 0 || n <= x || x < 0) {
        return false;
    }
    return true;
}

void BFS_RGB(int r, int c)
{
    char compare = board[r][c];
    queue<pair<int, int>> q;

    q.push(make_pair(r, c));
    isVisitedRGB[r][c] = true;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if (isSafe(cy, cx) && board[cy][cx] == compare && !isVisitedRGB[cy][cx]) {
                q.push(make_pair(cy, cx));
                isVisitedRGB[cy][cx] = true;
            }
        }
    }
}

void BFS_RRB(int r, int c)
{
    char compare = board[r][c];
    bool isRG = (compare != 'B' ? true : false);
    queue<pair<int, int>> q;

    q.push(make_pair(r, c));
    isVisitedRRB[r][c] = true;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if (isSafe(cy, cx)) {
                if (isRG && board[cy][cx] != 'B' && !isVisitedRRB[cy][cx]) {
                    q.push(make_pair(cy, cx));
                    isVisitedRRB[cy][cx] = true;
                }
                else if (!isRG && board[cy][cx] == 'B' && !isVisitedRRB[cy][cx]) {
                    q.push(make_pair(cy, cx));
                    isVisitedRRB[cy][cx] = true;
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    board = vector<vector<char>>(n, vector<char>(n));
    isVisitedRGB = isVisitedRRB = vector<vector<bool>>(n, vector<bool>(n, false));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> board[r][c];
        }
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (!isVisitedRGB[r][c]) {
                BFS_RGB(r, c);
                ++ansRGB;
            }
            if (!isVisitedRRB[r][c]) {
                BFS_RRB(r, c);
                ++ansRRB;
            }
        }
    }
    cout << ansRGB << ' ' << ansRRB << '\n';

    return 0;
}