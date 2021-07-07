#include <iostream>
#include <vector>

using namespace std;

int a, b, c, n;
vector<bool> v(301, false);

int main()
{
    cin >> a >> b >> c >> n;
    v[a] = v[b] = v[c] = true;
    for (int i = 0; i <= n; ++i) {
        if (i - a > 0 && v[i - a]) {
            v[i] = true;
            continue;
        }
        if (i - b > 0 && v[i - b]) {
            v[i] = true;
            continue;
        }
        if (i - c > 0 && v[i - c]) {
            v[i] = true;
            continue;
        }
    }
    cout << (int)v[n] << '\n';

    return 0;
}