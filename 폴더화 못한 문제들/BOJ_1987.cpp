// 비트마스크의 추가와 삭제에 대해서 조금 더 공부 필요

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int r, c, answer = -1;
int base = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<char>> board;

int dfs(int cx, int cy)
{
    if (cx < 0 || cy < 0 || cx >= r || cy >= c) return 0;
    if ((base & (1 << board[cx][cy] - 'A')) == 0) return 0;
    base ^= (1 << board[cx][cy] - 'A');

    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        int ccx = cx + dx[i];
        int ccy = cy + dy[i];

        cnt = max(cnt, dfs(ccx, ccy));
    }
    base |= (1 << board[cx][cy] - 'A');

    return cnt + 1;
}
int main()
{
    base = pow(2, 26) - 1;
    cin >> r >> c;
    board = vector<vector<char>>(r, vector<char>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> board[i][j];
        }
    }
    cout << dfs(0, 0) << '\n';

    return 0;
}