#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<char>> board;

void inputStar(int triSize, int spX, int spY)
{
    if (triSize == 3) {
        for (int i = 0; i < 5; i += 2) {
            if (i == 0) {
                board[i + spX][spY] = '*';
            }
            else if (i == 2) {
                board[i + spX][spY - 1] = board[i + spX][spY + 1] = '*';
            }
            else {
                for (int j = 0; j < 5; ++j) {
                    board[i + spX][spY - 2 + j] = '*';
                }
            }
        }
    }
    else {
        inputStar(triSize / 2, spX, spY);
        inputStar(triSize / 2, spX + triSize, spY - triSize / 2);
        inputStar(triSize / 2, spX + triSize, spY + triSize / 2);
    }
}

int main()
{
    cin >> n;
    board = vector<vector<char>>(2 * n - 1, vector<char>(2 * n, ' '));
    inputStar(n, 0, n - 1);
    int size = board.size();
    for (int i = 0; i < size; i += 2) {
        for (int j = 0; j < size + 1; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}