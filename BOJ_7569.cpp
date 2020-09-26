#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main()
{
    int n, m, h;
    cin >> n >> m >> h;

    queue<tuple<int, int, int, int>> q;
    vector<vector<vector<int>>> v(m, vector<vector<int>>(n, vector<int>(h)));
    vector<vector<vector<bool>>> isVisited(m, vector<vector<bool>>(n, vector<bool>(h, false)));
    for (int k = 0; k < h; ++k) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> v[i][j][k];
                if (v[i][j][k] == 1) {
                    q.push(make_tuple(i, j, k, 0));
                }
            }
        }
    }
    int maxDay;
    while (!q.empty()) {
        int cx = get<0>(q.front());
        int cy = get<1>(q.front());
        int cz = get<2>(q.front());
        int dist = get<3>(q.front());
        q.pop();

        // 예외 케이스
        if (cx < 0 || cy < 0 || cz < 0 || cx >= m || cy >= n || cz >= h) {
            continue;
        }
        // 이미 방문했다면
        if (isVisited[cx][cy][cz]) {
            continue;
        }
        isVisited[cx][cy][cz] = true;
        // 토마토가 없다면
        if (v[cx][cy][cz] == -1) {
            continue;
        }
        maxDay = dist;
        v[cx][cy][cz] = 1;
        for (int i = 0; i < 6; ++i) {
            q.push(make_tuple(cx + dx[i], cy + dy[i], cz + dz[i], dist + 1));
        }
    }
    for (int k = 0; k < h; ++k) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (v[i][j][k] == 0) {
                    cout << "-1\n";

                    return 0;
                }
            }
        }
    }
    cout << maxDay << '\n';

    return 0;
}