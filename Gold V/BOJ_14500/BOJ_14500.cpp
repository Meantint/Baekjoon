#include <iostream>
#include <vector>

using namespace std;

int n, m;
int answer = 0;
vector<vector<int>> board;
vector<vector<vector<int>>> info = {
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
};

void rotate90()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            int temp = info[i][j][0];
            info[i][j][0] = info[i][j][1];
            info[i][j][1] = -temp;
        }
    }
}

void reverse()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            info[i][j][0] *= -1;
        }
    }
}

bool isSafe(int r, int c, vector<vector<int>> rowInfo)
{
    for (int i = 0; i < 4; ++i) {
        int cr = r + rowInfo[i][0];
        int cc = c + rowInfo[i][1];
        if (n <= cr || cr < 0 || m <= cc || cc < 0) {
            return false;
        }
    }

    return true;
}

void BF()
{
    // 일자형, 정사각형
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (c + 3 < m) {
                int temp = board[r][c] + board[r][c + 1] + board[r][c + 2] + board[r][c + 3];
                if (answer < temp) {
                    answer = temp;
                }
            }
            if (r + 3 < n) {
                // cout << "r, c : " << r << ", " << c << '\n';
                int temp = board[r][c] + board[r + 1][c] + board[r + 2][c] + board[r + 3][c];
                // cout << "temp : " << temp << '\n';
                if (answer < temp) {
                    answer = temp;
                }
            }
            if (r + 1 < n && c + 1 < m) {
                int temp = board[r][c] + board[r + 1][c] + board[r][c + 1] + board[r + 1][c + 1];
                if (answer < temp) {
                    answer = temp;
                }
            }
        }
    }

    // 모양이 4, 8개가 나오는 케이스
    for (int kk = 0; kk < 2; ++kk) {
        reverse();
        for (int k = 0; k < 4; ++k) {
            rotate90();
            // LeftTop ~ RightBottom
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < m; ++c) {
                    for (int i = 0; i < 3; ++i) {  // info 3가지의 경우
                        if (isSafe(r, c, info[i])) {
                            int temp = 0;
                            for (int j = 0; j < 4; ++j) {
                                temp += board[r + info[i][j][0]][c + info[i][j][1]];
                            }
                            if (answer < temp) {
                                answer = temp;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    board = vector<vector<int>>(n, vector<int>(m));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> board[r][c];
        }
    }

    BF();
    cout << answer << '\n';

    return 0;
}