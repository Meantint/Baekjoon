#include <bits/stdc++.h>

using namespace std;

int main()
{
        int tc;
        cin >> tc;

        map<string, int> m;
        for (int i = 0; i < tc; ++i) {
                string str1, str2;
                cin >> str1 >> str2;

                if (str2 == "enter") {
                        m[str1] = 1;
                }
                else {
                        m.erase(str1);
                }
        }
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
                cout << it->first << '\n';
        }

        return 0;
}
