#include <bits/stdc++.h>

using namespace std;

int n, m, b;

int main()
{
    cin >> n >> m >> b;
    vector<vector<long long>> field(n, vector<long long>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
        }
    }

    int h = 0;
    int sum = 0;
    int need_block = 0;
    int answer = INT_MAX;
    int answer_h = -1;
    while (h <= 256) {
        need_block = 0;
        sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (h > field[i][j]) {
                    sum += (h - field[i][j]);
                }
                else {
                    sum += (field[i][j] - h) * 2;
                }
                need_block += (h - field[i][j]);
            }
        }
        if (need_block > b) {
            break;
        }
        if (sum <= answer) {
            answer = sum;
            answer_h = h;
        }
        ++h;
    }
    cout << answer << ' ' << answer_h << '\n';

    return 0;
}