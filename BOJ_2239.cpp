// board type = char..입니다..

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board(9, vector<char>(9));
vector<vector<bool>> row(9, vector<bool>(9, false));
vector<vector<bool>> col(9, vector<bool>(9, false));
vector<vector<bool>> arr33(9, vector<bool>(9, false));

bool isFull()
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '0') {
                return false;
            }
        }
    }
    return true;
}

// bool check(int cx, int cy)
// {
//     vector<int> isTrue(9, 0);
//     for (int i = 0; i < 9; ++i) {
//         int pos = board[i][cy] - '0' - 1;
//         if (pos == -1) continue;
//         ++isTrue[pos];
//         if (isTrue[pos] == 2) return false;
//     }
//     isTrue = vector<int>(9, 0);
//     for (int i = 0; i < 9; ++i) {
//         int pos = board[cx][i] - '0' - 1;
//         if (pos == -1) continue;
//         ++isTrue[pos];
//         if (isTrue[pos] == 2) return false;
//     }
//     isTrue = vector<int>(9, 0);
//     int ccx = cx / 3 * 3;
//     int ccy = cy / 3 * 3;
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             int pos = board[ccx + i][ccy + j] - '0' - 1;
//             if (pos == -1) continue;
//             ++isTrue[pos];
//             if (isTrue[pos] == 2) return false;
//         }
//     }

//     return true;
// }
bool check(int cx, int cy)
{
    int num = board[cx][cy] - '1';
    if (!row[cx][num] && !col[cy][num] &&
        !arr33[cx / 3 * 3 + cy / 3][num]) {
        row[cx][num] = true;
        col[cy][num] = true;
        arr33[cx / 3 * 3 + cy / 3][num] = true;
        return true;
    }
    return false;
}

void dfs(int cx, int cy)
{
    for (int num = 0; num < 9; ++num) {
        board[cx][cy] = '1' + num;
        if (!check(cx, cy)) continue;
        // printf("board[%d][%d] = %d\n", cx, cy, board[cx][cy] - '0');

        bool isFind = false;
        for (int i = cx; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '0') {
                    dfs(i, j);
                    isFind = true;
                    break;
                }
            }
            if (isFind) break;
        }
        if (isFull()) return;
        row[cx][num] = false;
        col[cy][num] = false;
        arr33[cx / 3 * 3 + cy / 3][num] = false;
    }
    board[cx][cy] = '0';
    return;
}

int main()
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
            if (board[i][j] == '0') continue;
            row[i][board[i][j] - '1'] = true;
            col[j][board[i][j] - '1'] = true;
            arr33[i / 3 * 3 + j / 3][board[i][j] - '1'] = true;
        }
    }
    bool isDone = false;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '0') {
                dfs(i, j);
                isDone = true;
                break;
            }
        }
        if (isDone) break;
    }
    // cout << '\n';
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    cout << '\n';

    return 0;
}