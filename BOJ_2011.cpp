#include <bits/stdc++.h>

using namespace std;

int main()
{
        string str;
        cin >> str;

        if (str[0] == '0') {
                cout << "0\n";
                return 0;
        }

        int size = str.size();
        vector<vector<int>> vec(size, vector<int>(2, 0));
        vec[0][0] = 1;
        vec[0][1] = 0;

        if (str[1] == '0')
                vec[1][0] = 0;
        else
                vec[1][0] = vec[0][0] + vec[0][1];

        string tmp = "" + str.substr(0, 2);
        if (stoi(tmp) <= 26)
                vec[1][1] = 1;
        else
                vec[1][1] = 0;

        for (int i = 2; i < size; ++i) {
                if (str[i] == '0')
                        vec[i][0] = 0;
                else
                        vec[i][0] = (vec[i - 1][0] + vec[i - 1][1]) % 1000000;

                string s = "" + str.substr(i - 1, 2);
                if (s[0] == '0') {
                        vec[i][1] = 0;
                }
                else if (stoi(s) <= 26)
                        vec[i][1] = (vec[i - 2][0] + vec[i - 2][1]) % 1000000;
                else {
                        vec[i][1] = 0;
                }
        }
        cout << (vec[size - 1][0] + vec[size - 1][1]) % 1000000 << '\n';

        return 0;
}
