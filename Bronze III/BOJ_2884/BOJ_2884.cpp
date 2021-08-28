#include <iostream>

using namespace std;

int h, m;

int main()
{
    cin >> h >> m;

    m -= 45;
    if (m < 0) {
        m += 60;
        --h;
        if (h < 0) {
            h += 24;
        }
    }
    cout << h << ' ' << m << '\n';

    return 0;
}