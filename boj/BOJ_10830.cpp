// 범위 잘 생각해서 자료형 결정하기

#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n;
ll m;
vector<vector<int>> arr;

vector<vector<int>> cal(vector<vector<int>> v1, vector<vector<int>> v2)
{
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += v1[i][k] * v2[k][j];
            }
            result[i][j] %= 1000;
        }
    }
    return result;
}

vector<vector<int>> dc(ll div)
{
    if (div == 1) {
        return arr;
    }
    if (div % 2 == 0) {
        vector<vector<int>> tmp = dc(div / 2);
        return cal(tmp, tmp);
    }
    else {
        return cal(dc(div - 1), arr);
    }
}

int main()
{
    cin >> n >> m;
    arr = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> answer = dc(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << answer[i][j] % 1000 << ' ';
        }
        cout << '\n';
    }

    return 0;
}