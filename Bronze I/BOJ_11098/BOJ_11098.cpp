#include <iostream>
#include <map>
#include <string>

using namespace std;

int tc, n;

int main()
{
    cin >> tc;
    while (tc--) {
        map<int, string> m;

        cin >> n;
        for (int i = 0; i < n; ++i) {
            int cost;
            string name;

            cin >> cost >> name;
            m[cost] = name;
        }

        cout << (--m.end())->second << '\n';
    }

    return 0;
}