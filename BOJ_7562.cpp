#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#define PII pair<int, int>

using namespace std;

int t, len;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
PII st, ed;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> len;
        cin >> st.first >> st.second;
        cin >> ed.first >> ed.second;
        vector<vector<bool>> board(len, vector<bool>(len, false));

        queue<tuple<int, int, int>> q;
        q.push(make_tuple(0, st.first, st.second));

        while (!q.empty()) {
            int cnt = get<0>(q.front());
            int x = get<1>(q.front());
            int y = get<2>(q.front());
            q.pop();

            if (x == ed.first && y == ed.second) {
                cout << cnt << '\n';
                break;
            }
            if (board[x][y]) continue;
            board[x][y] = true;
            for (int i = 0; i < 8; ++i) {
                int cx = x + dx[i];
                int cy = y + dy[i];
                if (cx < 0 || cy < 0 || cx >= len || cy >= len) continue;
                if (board[cx][cy]) continue;
                q.push(make_tuple(cnt + 1, cx, cy));
            }
        }
    }

    return 0;
}