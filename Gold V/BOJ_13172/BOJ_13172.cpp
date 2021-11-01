#include <iostream>

#define ll long long
#define MOD 1000000007

using namespace std;

int m;
ll n, s;

ll dc(int cnt)
{
    if (cnt == 1) {
        return n;
    }
    if (cnt % 2 == 0) {
        ll value = dc(cnt / 2);
        return value * value % MOD;
    }
    else {
        return dc(cnt - 1) * n % MOD;
    }
}

ll gcd(ll x, ll y)
{
    if (x % y == 0) {
        return y;
    }
    return gcd(y, x % y);
}

int main()
{
    cin >> m;

    ll answer = 0;
    while (m--) {
        cin >> n >> s;

        ll curGCD = gcd(n, s);
        n /= curGCD;
        s /= curGCD;

        // cout << dc(MOD - 2) << '\n';
        // cout << dc(MOD - 2) * s << '\n';
        // cout << dc(MOD - 2) * s % MOD << '\n';
        // cout << (dc(MOD - 2) * s) % MOD << '\n';

        answer += (dc(MOD - 2) * s % MOD);
        answer %= MOD;
    }
    cout << answer << '\n';

    return 0;
}