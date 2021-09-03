#include <iostream>
#include <string>
#include <vector>

#define ll long long
#define MOD 1234567891

using namespace std;

int n, r = 31;
string str;

int main()
{
    cin >> n >> str;

    ll ret = 0;
    int size = str.size();
    for (int i = 0; i < size; ++i) {
        ll alpha = str[i] - 'a' + 1;
        for (int j = 0; j < i; ++j) {
            alpha *= (1LL * r);
            alpha %= MOD;
        }
        ret += alpha;
        ret %= MOD;
    }
    cout << ret << '\n';

    return 0;
}