// 플로이드 와샬 알고리즘 사용

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define PII pair<int, int>

using namespace std;

int N;

int main()
{
    cin >> N;

    vector<vector<int>> adj(N, vector<int>(N, 0));
    vector<bool> isVisited(N, false);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> adj[i][j];
            if (adj[i][j] == 0) {
                adj[i][j] = 10000;
            }
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (adj[i][j] == 10000) {
                cout << '0' << ' ';
            }
            else {
                cout << '1' << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}