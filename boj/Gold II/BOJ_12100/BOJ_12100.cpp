#include <iostream>
#include <vector>

using namespace std;

int n;
int answer = 0;
vector<vector<int>> board;

// 시계 방향 90도 회전 하는 함수
vector<vector<int>> Rotate90(vector<vector<int>> tmp)
{
    vector<vector<int>> copy(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            copy[i][j] = tmp[n - j - 1][i];
        }
    }

    return copy;
}

// 행 기준 인덱스 0쪽으로 밀어넣음
void Move(vector<vector<int>>& tmp)
{
    vector<vector<bool>> is_combine(n, vector<bool>(n, false));
    for (int c = 0; c < n; ++c) {
        for (int r = 0; r < n; ++r) {
            if (tmp[r][c] == 0) {
                continue;
            }
            else {
                for (int k = r; k > 0; --k) {
                    // 이동하려는 부분의 값이 같고 결합 하지 않은 상태라면
                    if (tmp[k][c] == tmp[k - 1][c] && !is_combine[k - 1][c]) {
                        tmp[k][c] = 0;
                        tmp[k - 1][c] *= 2;
                        is_combine[k - 1][c] = true;

                        break;
                    }
                    // 빈 공간이면 이동
                    else if (tmp[k - 1][c] == 0) {
                        tmp[k - 1][c] = tmp[k][c];
                        tmp[k][c] = 0;
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
}

void FindMaxNum(vector<vector<int>> tmp)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (answer < tmp[i][j]) {
                answer = tmp[i][j];
                // for (int r = 0; r < n; ++r) {
                //     for (int c = 0; c < n; ++c) {
                //         cout << tmp[r][c] << ' ';
                //     }
                //     cout << '\n';
                // }
                // cout << '\n';
            }
        }
    }
}

// 남은 이동 횟수 : cnt
void Dfs(int cnt, vector<vector<int>> tmp)
{
    if (cnt == 0) {
        FindMaxNum(tmp);

        return;
    }
    --cnt;

    vector<vector<int>> copy;
    for (int i = 0; i < 4; ++i) {
        copy = tmp;
        Move(copy);
        Dfs(cnt, copy);

        tmp = Rotate90(tmp);
    }
}

void solve()
{
    Dfs(5, board);
}

int main()
{
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    solve();

    cout << answer << '\n';

    return 0;
}