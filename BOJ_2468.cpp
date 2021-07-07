#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;
int h, cnt = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> board;
vector<vector<bool>> isCheck;

void dfs(int x, int y)
{
    isCheck[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 0 || cy < 0 || cx >= n || cy >= n) continue;
        if (isCheck[cx][cy]) continue;
        if (board[cx][cy] <= h) {
            isCheck[cx][cy] = true;
            continue;
        }
        dfs(cx, cy);
    }
}

int main()
{
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    for (h = 0; h < 101; ++h) {
        cnt = 0;
        isCheck = vector<vector<bool>>(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] > h && !isCheck[i][j]) {
                    ++cnt;
                    dfs(i, j);
                }
                else {
                    isCheck[i][j] = true;
                }
            }
        }
        answer = max(answer, cnt);
        // cout << "isGood\n";
    }
    cout << answer << '\n';

    return 0;
}