#include <iostream>
#include <vector>

using namespace std;

int tc, k, n;
vector<vector<int>> info(15, vector<int>(15, 0));

int main()
{
    for (int i = 1; i < 15; ++i) {
        info[0][i] = i;
    }
    for (int r = 1; r < 15; ++r) {
        for (int c = 1; c < 15; ++c) {
            info[r][c] = info[r - 1][c] + info[r][c - 1];
        }
    }

    cin >> tc;
    while (tc--) {
        cin >> k >> n;
        cout << info[k][n] << '\n';
    }

    return 0;
}