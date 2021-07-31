#include <iostream>
#include <vector>

using namespace std;

int n, l, r;
vector<vector<int>> board;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool isSafe(int y, int x)
{
    if (y < 0 || n <= y || x < 0 || n <= x) {
        return false;
    }

    return true;
}

// (area, count)
pair<int, int> dfs(int y, int x, int count, vector<vector<int>>& cur_info)
{
    pair<int, int> ret = make_pair(board[y][x], 1);

    cur_info[y][x] = count;

    for (int i = 0; i < 4; ++i) {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (isSafe(cy, cx)) {
            if (cur_info[cy][cx] == -1) {
                int temp = abs(board[cy][cx] - board[y][x]);

                if (l <= temp && temp <= r) {
                    pair<int, int> temp = dfs(cy, cx, count, cur_info);
                    ret.first += temp.first;
                    ret.second += temp.second;
                }
            }
        }
    }

    return ret;
}

void change_value(int y, int x, int count, vector<vector<int>>& cur_info, vector<int>& count_list)
{
    // cout << "count_list[count] : " << count_list[count] << '\n';
    board[y][x] = count_list[count];
    cur_info[y][x] = -1;

    for (int i = 0; i < 4; ++i) {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (isSafe(cy, cx)) {
            if (cur_info[cy][cx] == count) {
                change_value(cy, cx, count, cur_info, count_list);
            }
        }
    }
}

int solve()
{
    int ret = 0;

    while (1) {
        // cout << ret << '\n';
        vector<vector<int>> cur_info(n, vector<int>(n, -1));
        vector<int> count_list(n * n, -1);  // (target_count, value)

        int count = 0;
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                if (cur_info[y][x] != -1) {
                    continue;
                }
                pair<int, int> temp = dfs(y, x, count, cur_info);
                if (temp.second != 1) {
                    count_list[count] = temp.first / temp.second;
                    // cout << temp.first << ", " << temp.second << '\n';
                }
                else {
                    cur_info[y][x] = -1;
                }
                ++count;
            }
        }

        int change_count = 0;
        // int count_list_size = count_list.size();
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                if (cur_info[y][x] != -1) {
                    change_value(y, x, cur_info[y][x], cur_info, count_list);
                    ++change_count;
                }
            }
        }

        if (change_count == 0) {
            break;
        }

        ++ret;
    }

    return ret;
}

int main()
{
    cin >> n >> l >> r;
    board = vector<vector<int>>(n, vector<int>(n, 0));

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            cin >> board[y][x];
        }
    }

    cout << solve() << '\n';

    return 0;
}