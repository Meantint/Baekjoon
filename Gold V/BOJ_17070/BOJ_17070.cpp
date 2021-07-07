#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, answer = 0;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};
vector<vector<int>> board;
// 가로, 세로의 위치 & 파이프 방향(0: 가로, 1: 대각선, 2: 세로)
vector<vector<vector<int>>> dp;

// 파이프의 끝 부분이 범위안에 들어오는지와 벽이 있는지 없는지 확인 해주는 함수
bool isCheck(int x, int y, int dir)
{
    if (x == n - 1 && y == n - 1) {
        return true;
    }
    if (x + dx[dir] >= n || y + dy[dir] >= n) {
        return false;
    }

    // 가로나 세로인 경우
    if (dir == 0 || dir == 2) {
        if (board[x + dx[dir]][y + dy[dir]] == 1) {
            return false;
        }
    }
    // 대각선인 경우
    else {
        for (int i = 0; i < 3; ++i) {
            if (board[x + dx[i]][y + dy[i]] == 1) {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n));  // 초기화
    dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(3, 0)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // 파이프가 가로인 경우
            if (isCheck(i, j, 0)) {
                // 왼쪽의 범위에서 자유로울 때
                if (j - 1 >= 0) {
                    dp[i][j][0] += dp[i][j - 1][0];
                    // 위쪽의 범위도 자유롭다면 대각선에서도 가능
                    if (i - 1 >= 0) {
                        dp[i][j][0] += dp[i - 1][j - 1][1];
                    }
                }
            }
            // 파이프가 세로인 경우
            if (isCheck(i, j, 2)) {
                // 위쪽의 범위에서 자유로울 때
                if (i - 1 >= 0) {
                    dp[i][j][2] += dp[i - 1][j][2];
                    // 왼쪽의 범위도 자유롭다면 대각선에서도 가능
                    if (j - 1 >= 0) {
                        dp[i][j][2] += dp[i - 1][j - 1][1];
                    }
                }
            }
            // 파이프가 대각선인 경우
            if (isCheck(i, j, 1)) {
                // 왼쪽의 범위에서 자유로울 때
                if (j - 1 >= 0) {
                    dp[i][j][1] += dp[i][j - 1][0];
                }
                // 위쪽의 범위에서 자유로울 때
                if (i - 1 >= 0) {
                    dp[i][j][1] += dp[i - 1][j][2];
                }
                // 양쪽의 범위 모두 자유로울 때
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dp[i][j][1] += dp[i - 1][j - 1][1];
                }
            }
        }
    }
    // for (int k = 0; k < 3; ++k) {
    //     for (int i = 0; i < n; ++i) {
    //         for (int j = 0; j < n; ++j) {
    //             cout << dp[i][j][k] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }
    answer = dp[n - 1][n - 1][1];
    cout << answer << '\n';

    return 0;
}