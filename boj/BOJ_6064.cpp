#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int t;

int gcd(int x, int y)
{
    if (x < y) {
        swap(x, y);
    }
    if (x % y == 0) {
        return y;
    }
    else {
        return gcd(y, x % y);
    }
}

int main()
{
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int g = (m * n) / gcd(m, n);
        bool isNull = true;
        for (int st = x; st <= g; st += m) {
            if (st % n == y % n) {
                isNull = false;
                cout << st << '\n';
                break;
            }
        }
        if (isNull) {
            cout << "-1\n";
        }
    }

    return 0;
}