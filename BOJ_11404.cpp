// 마지막에 갈 수 없는 경우를 0으로 바꿔줘야 한다.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#define PII pair<int, int>
#define INF 100000000

using namespace std;

int n, m;
vector<vector<int>> adj;

void floyd()
{
    for (int i = 0; i < n; ++i) {
        adj[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << setw(9) << adj[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout.setf(ios::right);
    cin >> n >> m;
    adj = vector<vector<int>>(n, vector<int>(n, INF));
    for (int i = 0; i < m; ++i) {
        int st, ed, dist;
        cin >> st >> ed >> dist;

        adj[st - 1][ed - 1] = min(adj[st - 1][ed - 1], dist);
    }
    // cout << '\n';
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << setw(9) << adj[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    floyd();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj[i][j] == INF) {
                cout << '0' << ' ';
                continue;
            }
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}