#include <algorithm>
#include <iostream>
#include <vector>

#define INIT 30000

using namespace std;

int n, m;
vector<vector<int>> info;

int main()
{
    cin >> n >> m;
    info = vector<vector<int>>(n + 1, vector<int>(n + 1, INIT));

    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        info[v1][v2] = 1;
        info[v2][v1] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        info[i][i] = 0;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                info[i][j] = min(info[i][j], info[i][k] + info[k][j]);
            }
        }
    }

    int ans = 0;
    int ret = INIT;
    for (int i = 1; i <= n; ++i) {
        int temp = 0;
        for (int j = 1; j <= n; ++j) {
            temp += info[i][j];
        }
        if (ret > temp) {
            ret = temp;
            ans = i;
        }
    }
    cout << ans << '\n';

    return 0;
}