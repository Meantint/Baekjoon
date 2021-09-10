#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n;
ll k;
vector<vector<int>> matrix;

vector<vector<int>> cal(vector<vector<int>> m1, vector<vector<int>> m2)
{
    vector<vector<int>> ret(n, vector<int>(n, 0));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            for (int k = 0; k < n; ++k) {
                ret[r][c] += m1[r][k] * m2[k][c];
            }
            ret[r][c] %= 1000;
        }
    }

    return ret;
}

vector<vector<int>> DC(ll num)
{
    if (num == 1) {
        return matrix;
    }

    if (num % 2 == 0) {
        vector<vector<int>> temp = DC(num / 2);
        return cal(temp, temp);
    }
    else {
        return cal(DC(num - 1), matrix);
    }
}

int main()
{
    cin >> n >> k;
    matrix.resize(n, vector<int>(n));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> matrix[r][c];
            matrix[r][c] %= 1000;
        }
    }

    vector<vector<int>> answer = DC(k);
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << answer[r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}