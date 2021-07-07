#include <algorithm>
#include <iostream>
#include <vector>

#define PII pair<int, int>
#define INF 100000000

using namespace std;

int n, m, r;
vector<vector<int>> adj;
vector<int> item;

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
    }
}

int main()
{
    cin >> n >> m >> r;
    item = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> item[i];
    }
    adj = vector<vector<int>>(n, vector<int>(n, INF));
    for (int i = 0; i < r; ++i) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;

        adj[v1 - 1][v2 - 1] = dist;
        adj[v2 - 1][v1 - 1] = dist;
    }
    floyd();
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << adj[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (adj[i][j] <= m) cnt += item[j];
        }
        answer = max(answer, cnt);
    }
    cout << answer << '\n';

    return 0;
}