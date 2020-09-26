#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    int n, m;
    cin >> n >> m;

    queue<tuple<int, int, int>> q;
    vector<vector<int>> v(m, vector<int>(n));
    vector<vector<bool>> isVisited(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
            if (v[i][j] == 1) {
                q.push(make_tuple(i, j, 0));
            }
        }
    }
    int maxDay;
    while (!q.empty()) {
        int cx = get<0>(q.front());
        int cy = get<1>(q.front());
        int dist = get<2>(q.front());
        q.pop();

        // 예외 케이스
        if (cx < 0 || cy < 0 || cx >= m || cy >= n) {
            continue;
        }
        // 이미 방문했다면
        if (isVisited[cx][cy]) {
            continue;
        }
        isVisited[cx][cy] = true;
        // 토마토가 없다면
        if (v[cx][cy] == -1) {
            continue;
        }
        maxDay = dist;
        v[cx][cy] = 1;
        for (int i = 0; i < 4; ++i) {
            q.push(make_tuple(cx + dx[i], cy + dy[i], dist + 1));
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (v[i][j] == 0) {
                cout << "-1\n";

                return 0;
            }
        }
    }
    cout << maxDay << '\n';

    return 0;
}