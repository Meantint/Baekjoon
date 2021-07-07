#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
int answer = 100;
vector<vector<char>> board;

// 시작하는 왼쪽 윗부분의 좌표가 (start_x, start_y)일 때 바꿔야하는 개수 출력
// 왼쪽 윗분을 항상 'B'로 해야한다고 가정, 개수가 32보다 큰 경우 (64 - 개수)를 해준다.
// 개수가 32보다 큰 경우는 왼쪽 윗부분이 'W'로 했을 때가 cnt가 더 작게 나오는 경우이다.
int changeCount(int start_x, int start_y)
{
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            // (i + j)가 짝수인데 board[i+start_x][j+start_y]가 'W'인 경우
            if ((i + j) % 2 == 0 && board[i + start_x][j + start_y] == 'W') {
                ++cnt;
            }
            // (i + j)가 홀수인데 board[i+start_x][j+start_y]가 'B'인 경우
            else if ((i + j) % 2 == 1 && board[i + start_x][j + start_y] == 'B') {
                ++cnt;
            }
        }
    }
    // cnt가 32보다 크다면 (64 - cnt), 같거나 작다면 cnt를 리턴한다.
    return ((cnt > 32) ? 64 - cnt : cnt);
}

int main()
{
    cin >> n >> m;
    board = vector<vector<char>>(n, vector<char>(m));
    for (auto& row : board) {
        for (auto& c : row) {
            cin >> c;
        }
    }
    for (int i = 0; i < n; ++i) {
        // 행이 범위를 벗어나면
        if (i + 7 >= n) {
            break;
        }
        for (int j = 0; j < m; ++j) {
            // 열이 범위를 벗어나면
            if (j + 7 >= m) {
                break;
            }
            answer = min(answer, changeCount(i, j));
        }
    }
    cout << answer << '\n';

    return 0;
}