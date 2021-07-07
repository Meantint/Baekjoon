#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

int main()
{
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<vector<int>> answer(0, vector<int>(m, 0));
    vector<int> prev(m, -1);
    do {
        bool isDiff = false;
        for (int i = 0; i < m; ++i) {
            if (prev[i] != v[i]) {
                isDiff = true;
                break;
            }
        }
        if (isDiff) {
            for (int i = 0; i < m; ++i) {
                prev[i] = v[i];
            }
            answer.push_back(prev);
        }
    } while (next_permutation(v.begin(), v.end()));

    for (int i = 0; i < answer.size(); ++i) {
        for (int j = 0; j < m; ++j) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}