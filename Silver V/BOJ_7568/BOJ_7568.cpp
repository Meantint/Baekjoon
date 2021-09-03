#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> info;

int main()
{
    cin >> n;
    info = vector<vector<int>>(n, vector<int>(3, 1));
    for (int i = 0; i < n; ++i) {
        cin >> info[i][0] >> info[i][1];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (info[i][0] < info[j][0] && info[i][1] < info[j][1]) {
                ++info[i][2];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << info[i][2] << ' ';
    }
    cout << '\n';

    return 0;
}