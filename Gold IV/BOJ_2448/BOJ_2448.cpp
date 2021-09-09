#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<char>> board;

void DC(int r, int c, int size)
{
    if (size == 3) {
        board[r][c] = '*';
        board[r + 1][c - 1] = board[r + 1][c + 1] = '*';
        for (int i = 0; i < 5; ++i) {
            board[r + 2][c + i - 2] = '*';
        }

        return;
    }

    int newSize = size / 2;
    DC(r, c, newSize);
    DC(r + newSize, c - newSize, newSize);
    DC(r + newSize, c + newSize, newSize);
}

int main()
{
    cin >> n;
    board = vector<vector<char>>(n, vector<char>(n * 2 - 1, ' '));

    DC(0, (n * 2 - 1) / 2, n);

    int rSize = board.size();
    int cSize = board[0].size();
    for (int r = 0; r < rSize; ++r) {
        for (int c = 0; c < cSize; ++c) {
            cout << board[r][c];
        }
        cout << '\n';
    }

    return 0;
}