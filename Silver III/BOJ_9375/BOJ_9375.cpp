#include <iostream>
#include <map>
#include <string>
#include <vector>

#define ll long long

using namespace std;

int tc, n;

int main()
{
    cin >> tc;
    while (tc--) {
        map<string, int> m;
        cin >> n;
        while (n--) {
            string str1, str2;
            cin >> str1 >> str2;

            if (m.find(str2) == m.end()) {
                m[str2] = 1;
            }
            else {
                ++m[str2];
            }
        }

        ll ret = 1;
        for (auto& iter : m) {
            ret *= (1LL * (iter.second + 1));
        }
        cout << ret - 1 << '\n';
    }

    return 0;
}