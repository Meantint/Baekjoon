#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v(21, 0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x = 0;
        string str = "";
        cin >> str;

        if (str.substr(0, 3) == "add") {
            cin >> x;
            v[x] = 1;
        }
        else if (str.substr(0, 3) == "all") {
            for (int i = 1; i < 21; ++i) {
                v[i] = 1;
            }
        }
        else if (str.substr(0, 5) == "check") {
            cin >> x;
            cout << v[x] << '\n';
        }
        else if (str.substr(0, 5) == "empty") {
            for (int i = 1; i < 21; ++i) {
                v[i] = 0;
            }
        }
        else if (str.substr(0, 6) == "remove") {
            cin >> x;
            v[x] = 0;
        }
        else if (str.substr(0, 6) == "toggle") {
            cin >> x;
            v[x] = (v[x] + 1) % 2;
        }
    }

    return 0;
}