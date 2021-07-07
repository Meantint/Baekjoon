#include <iostream>

using namespace std;

int n, row = 0, col;
char board[100][100];
bool isVisited[100][100];

int main()
{
    // 초기화
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            isVisited[i][j] = false;
        }
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '.') {
                if (i == 0 || (i - 1 >= 0 && board[i - 1][j] == 'X')) {
                    if (i + 1 < n && board[i + 1][j] == '.') {
                        ++row;
                    }
                }
                if (j == 0 || (j - 1 >= 0 && board[i][j - 1] == 'X')) {
                    if (j + 1 < n && board[i][j + 1] == '.') {
                        ++col;
                    }
                }
            }
        }
    }
    cout << col << ' ' << row << '\n';

    return 0;
}