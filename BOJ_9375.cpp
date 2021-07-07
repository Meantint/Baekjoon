#include <bits/stdc++.h>

using namespace std;

int main()
{
        int tc;
        cin >> tc;

        for (int i = 0; i < tc; ++i) {
                int tc1;
                cin >> tc1;

                map<string, int> m;
                for (int j = 0; j < tc1; ++j) {
                        string str1, str2;
                        cin >> str1 >> str2;

                        if (m.count(str2) > 0) {
                                m[str2] += 1;
                        }
                        else {
                                m[str2] = 1;
                        }
                }
                int answer = 1;
                for (auto it = m.begin(); it != m.end(); ++it) {
                        answer *= (it->second + 1);
                }
                --answer;
                cout << answer << '\n';
        }

        return 0;
}
