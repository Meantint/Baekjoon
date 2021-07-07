#include <iostream>
#include <vector>

using namespace std;

int n, whiteCnt = 0, blueCnt = 0;
vector<vector<int>> board;

void solve(int x, int y, int size)
{
    int cnt = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cnt += board[x + i][y + j];
        }
    }
    // 탐색한 곳 전체가 파란색 종이일 경우
    if (cnt == size * size) {
        ++blueCnt;

        return;
    }
    // 탐색한 곳 전체가 하얀색 종이일 경우
    else if (cnt == 0) {
        ++whiteCnt;

        return;
    }
    else {
        int half = size / 2;
        solve(x, y, half);
        solve(x + half, y, half);
        solve(x, y + half, half);
        solve(x + half, y + half, half);
    }

    return;
}

int main()
{
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n));
    for (auto& row : board) {
        for (auto& elem : row) {
            cin >> elem;
        }
    }
    solve(0, 0, n);
    cout << whiteCnt << '\n'
         << blueCnt << '\n';

    return 0;
}