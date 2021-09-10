#include <iostream>
#include <vector>

#define ll long long
#define MOD 1000000007

using namespace std;

ll n;
vector<vector<ll>> matrix = {{0, 1}, {1, 1}};

vector<vector<ll>> Cal(vector<vector<ll>> m1, vector<vector<ll>> m2)
{
    vector<vector<ll>> ret(2, vector<ll>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                ret[i][j] += m1[i][k] * m2[k][j];
            }
            ret[i][j] %= MOD;
        }
    }

    return ret;
}

vector<vector<ll>> DC(ll k)
{
    if (k == 1) {
        return matrix;
    }

    if (k % 2 == 0) {
        vector<vector<ll>> temp = DC(k / 2);
        return Cal(temp, temp);
    }
    else {
        return Cal(DC(k - 1), matrix);
    }
}

int main()
{
    cin >> n;

    vector<vector<ll>> answer = DC(++n);

    cout << answer[0][0] << '\n';

    return 0;
}