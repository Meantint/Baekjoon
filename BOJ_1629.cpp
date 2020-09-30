// 분할 정복 이용해야함

#include <iostream>

using namespace std;

typedef long long ll;

ll a, b, c;

ll cal(ll a, ll b)
{
    if (b == 0) {
        return 1;
    }
    else if (b == 1) {
        return a;
    }

    if (b % 2 == 1) {
        return cal(a, b - 1) * a;
    }
    else {
        ll half = cal(a, b / 2) % c;

        return half * half % c;
    }
}

int main()
{
    cin >> a >> b >> c;
    cout << cal(a, b) % c << '\n';

    return 0;
}