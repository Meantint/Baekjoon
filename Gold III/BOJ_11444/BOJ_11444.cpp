#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector<vector<ll>> v = {
    {1, 1},
    {1, 0},
};
ll n;

vector<vector<ll>> cal(vector<vector<ll>> v1, vector<vector<ll>> v2)
{
    vector<vector<ll>> res(2, vector<ll>(2));

    res[0][0] = ((v1[0][0] * v2[0][0]) % 1000000007 + (v1[0][1] * v2[1][0]) % 1000000007) % 1000000007;
    res[0][1] = ((v1[0][0] * v2[0][1]) % 1000000007 + (v1[0][1] * v2[1][1]) % 1000000007) % 1000000007;
    res[1][0] = ((v1[1][0] * v2[0][0]) % 1000000007 + (v1[1][1] * v2[1][0]) % 1000000007) % 1000000007;
    res[1][1] = ((v1[1][0] * v2[0][1]) % 1000000007 + (v1[1][1] * v2[1][1]) % 1000000007) % 1000000007;

    return res;
}

vector<vector<ll>> dc(ll num)
{
    if (num == 1) {
        return v;
    }

    if ((num & 1) == 0) {
        vector<vector<ll>> res = dc(num / 2);
        return cal(res, res);
    }
    else {
        return cal(dc(num - 1), v);
    }
}

void solve()
{
    vector<vector<ll>> answer = dc(n);

    cout << answer[0][1] << '\n';
}

int main()
{
    cin >> n;

    solve();

    return 0;
}