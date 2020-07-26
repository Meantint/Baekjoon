#include <bits/stdc++.h>

using namespace std;

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n, m;
        cin >> n >> m;

        vector<string> v1;
        map<string, int> v2;
        for (int i = 0; i < n; ++i) {
                string str;
                cin >> str;

                v1.push_back(str);
                v2[str] = i;
        }

        for (int i = 0; i < m; ++i) {
                string str;
                cin >> str;

                if (str[0] - '0' >= 0 && str[0] - '0' <= 9) {
                        cout << v1[stoi(str) - 1] << '\n';
                }
                else {
                        cout << v2[str] + 1 << '\n';
                }
        }

        return 0;
}
