#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int n;
int answer = 0;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};

int main()
{
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    // 파이프 위치 중 왼쪽 위에 있는 pos의 (x, y), 3번째인자는 가로, 세로, 대각을 나타내는 값
    // 0 : 가로, 1 : 세로, 2 : 대각선
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    while (!q.empty()) {
        int cx = get<0>(q.front());
        int cy = get<1>(q.front());
        int dir = get<2>(q.front());
        q.pop();

        if (dir == 0 || dir == 1) {
            if (cx == n || cy == n || board[cx][cy] == 1) continue;
            if (cx + dx[dir] == n || cy + dy[dir] == n || board[cx + dx[dir]][cy + dy[dir]] == 1) continue;
        }
        else {
            bool isPos = true;
            for (int i = 0; i < 3; ++i) {
                if (cx + dx[i] == n || cy + dy[i] == n || board[cx + dx[i]][cy + dy[i]] == 1) {
                    isPos = false;
                    break;
                }
            }
            if (isPos == false) continue;
        }
        if (cx + dx[dir] == n - 1 && cy + dy[dir] == n - 1) {
            ++answer;
            continue;
        }
        if (dir == 0 || dir == 2) {
            q.push(make_tuple(cx + dx[dir], cy + dy[dir], 0));
        }
        if (dir == 1 || dir == 2) {
            q.push(make_tuple(cx + dx[dir], cy + dy[dir], 1));
        }
        q.push(make_tuple(cx + dx[dir], cy + dy[dir], 2));
    }
    cout << answer << '\n';

    return 0;
}