#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<string> board;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int answer = 0;
int base = 0;

bool isSafe(int y, int x)
{
    if (0 <= y && y < n && 0 <= x && x < m) {
        return true;
    }
    return false;
}

void dfs(int y, int x, int cnt)
{
    // cout << y << ", " << x << ", " << cnt << '\n';
    int pos = (1 << (board[y][x] - 'A'));
    if (base & pos) {  // 이미 방문한 적 있는 알파벳이라면
        --cnt;
        if (answer < cnt) {
            answer = cnt;
        }
        return;
    }

    base |= pos;

    for (int i = 0; i < 4; ++i) {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (isSafe(cy, cx)) {
            dfs(cy, cx, cnt + 1);
        }
    }

    base ^= pos;

    return;
}

int main()
{
    cin >> n >> m;
    board.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    dfs(0, 0, 1);

    cout << answer << '\n';

    return 0;
}