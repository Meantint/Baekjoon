#include <iostream>
#include <vector>

using namespace std;

int n, m, bSize;
int cx1, cy1, cx2, cy2;
vector<vector<int>> board;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    board = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    bSize = n + 1;
    for (int i = 1; i < bSize; ++i) {
        for (int j = 1; j < bSize; ++j) {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i < bSize; ++i) {
        for (int j = 1; j < bSize; ++j) {
            board[i][j] += (board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1]);
        }
    }
    while (m--) {
        cin >> cx1 >> cy1 >> cx2 >> cy2;
        cout << board[cx2][cy2] + board[cx1 - 1][cy1 - 1] - board[cx1 - 1][cy2] - board[cx2][cy1 - 1] << '\n';
    }

    return 0;
}