#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int x1, x2, y_1, y_2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    vector<vector<int>> prefixSum(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            cin >> v[i][j];
            prefixSum[i][j] = v[i][j];
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + v[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> x1 >> y_1 >> x2 >> y_2;
        cout << prefixSum[x2][y_2] + prefixSum[x1 - 1][y_1 - 1] - prefixSum[x2][y_1 - 1] - prefixSum[x1 - 1][y_2] << '\n';
    }

    return 0;
}