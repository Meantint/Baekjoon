#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    map<string, string> mp;
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;

        mp[s1] = s2;
    }
    for (int i = 0; i < m; ++i) {
        string s1;
        cin >> s1;

        cout << mp[s1] << '\n';
    }

    return 0;
}