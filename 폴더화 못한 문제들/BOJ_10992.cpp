#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // vector<vector<char>> vec(n, vector<char>(2 * n - 1));

    // for (int i = 0; i < n - 1; ++i) {
    //     vec[i][n - i - 1] = vec[i][n + i - 1] = '*';
    // }
    // for (int i = 0; i < 2 * n - 1; ++i) {
    //     vec[n - 1][i] = '*';
    // }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < 2 * n - 1; ++j) {
    //         cout << vec[i][j];
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < 2 * n - 1; ++j) {
            if (j == n + i - 1) {
                cout << "*";
                break;
            }
            else if (j == n - i - 1) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << '\n';
    }
    for (int i = 0; i < 2 * n - 1; ++i) {
        cout << "*";
    }

    return 0;
}