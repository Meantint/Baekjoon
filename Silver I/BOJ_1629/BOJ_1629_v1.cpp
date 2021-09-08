#include <iostream>

#define ll long long

using namespace std;

ll a, b, c;

ll myDC(int cnt)
{
    if (cnt == 1) {
        return a % c;
    }
    if (cnt % 2 == 1) {
        return (myDC(cnt - 1) * a) % c;
    }
    else {
        ll tmp = myDC(cnt / 2);
        return (tmp * tmp) % c;
    }
}

int main()
{
    cin >> a >> b >> c;
    cout << myDC(b) % c << '\n';

    return 0;
}