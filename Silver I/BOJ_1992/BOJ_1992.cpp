#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
string answer = "";
vector<vector<char>> board;

bool isSame(int y, int x, int len)
{
    char base = board[y][x];
    for (int r = 0; r < len; ++r) {
        for (int c = 0; c < len; ++c) {
            if (base != board[y + r][x + c]) {
                return false;
            }
        }
    }

    return true;
}

void DFS(int y, int x, int len)
{
    if (isSame(y, x, len)) {
        answer += board[y][x];
    }
    else {
        answer += '(';

        int newLen = len / 2;
        for (int r = 0; r < 2; ++r) {
            for (int c = 0; c < 2; ++c) {
                DFS(y + r * newLen, x + c * newLen, newLen);
            }
        }

        answer += ')';
    }
}

int main()
{
    cin >> n;
    board = vector<vector<char>>(n, vector<char>(n));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> board[r][c];
        }
    }

    DFS(0, 0, n);

    cout << answer << '\n';

    return 0;
}