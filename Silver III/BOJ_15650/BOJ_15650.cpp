#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> answer;

int main()
{
    cin >> n >> m;

    vector<int> v(n, 1);
    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        num[i] = i + 1;
    }
    for (int i = 0; i < m; ++i) {
        v[i] = 0;
    }
    sort(v.begin(), v.end());
    do {
        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            if (v[i] == 0) {
                tmp.push_back(num[i]);
            }
        }
        answer.push_back(tmp);
    } while (next_permutation(v.begin(), v.end()));
    for (auto& ans : answer) {
        for (auto& elem : ans) {
            cout << elem << ' ';
        }
        cout << '\n';
    }

    return 0;
}