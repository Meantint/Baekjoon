#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, m;
string s1, s2;
map<string, string> info;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        info[s1] = s2;
    }
    for (int i = 0; i < m; ++i) {
        cin >> s1;
        cout << info[s1] << '\n';
    }

    return 0;
}