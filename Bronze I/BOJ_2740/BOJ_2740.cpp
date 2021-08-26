#include <iostream>
#include <vector>

using namespace std;

int n, m;

int main()
{
    // array 1
    cin >> n >> m;
    vector<vector<int>> arr1(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr1[i][j];
        }
    }

    // array 2
    cin >> n >> m;
    vector<vector<int>> arr2(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr2[i][j];
        }
    }

    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
    for (int i = 0; i < answer.size(); ++i) {
        for (int j = 0; j < answer[0].size(); ++j) {
            for (int k = 0; k < arr1[0].size(); ++k) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    for (int i = 0; i < answer.size(); ++i) {
        for (int j = 0; j < answer[0].size(); ++j) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    return 0;
}