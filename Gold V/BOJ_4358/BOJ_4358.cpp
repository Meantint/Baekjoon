#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count = 0;
    while (getline(cin, str)) {
        ++count;
        if (m.find(str) != m.end()) {
            ++m[str];
        }
        else {
            m[str] = 1;
        }
    }

    cout << fixed;
    cout.precision(4);
    for (auto iter : m) {
        cout << iter.first << ' ' << (double)100 * ((double)iter.second / (double)count) << '\n';
    }

    return 0;
}