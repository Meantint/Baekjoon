#include <algorithm>
#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

int n, m;
vector<vector<int>> floyd;

int main()
{
    cin >> n >> m;
    floyd.resize(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; ++i) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;

        floyd[v1][v2] = min(floyd[v1][v2], dist);
        // floyd[v2][v1] = dist;
    }

    for (int i = 1; i <= n; ++i) {
        floyd[i][i] = 0;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (floyd[i][j] == INF) {
                cout << 0 << ' ';
            }
            else {
                cout << floyd[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}