#include <iostream>
#include <string>
#include <vector>

using namespace std;

int tc;
string str;

int main()
{
    cin >> tc;
    while (tc--) {
        cin >> str;

        int ret = 0;
        vector<bool> alpha(26, false);
        for (auto ch : str) {
            alpha[ch - 'A'] = true;
        }

        for (int i = 0; i < 26; ++i) {
            if (!alpha[i]) {
                ret += ('A' + i);
            }
        }

        cout << ret << '\n';
    }

    return 0;
}