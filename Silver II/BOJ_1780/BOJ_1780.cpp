#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> answer(3, 0);
vector<vector<int>> board;

bool isSame(int y, int x, int len)
{
    int base = board[y][x];

    for (int r = 0; r < len; ++r) {
        for (int c = 0; c < len; ++c) {
            if (board[y + r][x + c] != base) {
                return false;
            }
        }
    }

    return true;
}

void DFS(int y, int x, int len)
{
    if (isSame(y, x, len)) {
        ++answer[board[y][x] + 1];

        return;
    }

    int newLen = len / 3;
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            DFS(y + r * newLen, x + c * newLen, newLen);
        }
    }
}

int main()
{
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> board[r][c];
        }
    }

    DFS(0, 0, n);

    for (int i = 0; i < 3; ++i) {
        cout << answer[i] << '\n';
    }

    return 0;
}