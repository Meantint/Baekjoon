#include <iostream>
#include <set>
#include <string>

using namespace std;

int n, m;
set<string> s;

int main()
{
    int ret = 0;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;

        s.insert(temp);
    }
    for (int i = 0; i < m; ++i) {
        string temp;
        cin >> temp;

        if (s.find(temp) != s.end()) {
            ++ret;
        }
    }

    cout << ret << '\n';

    return 0;
}