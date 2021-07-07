#include <iostream>
#include <string>

using namespace std;

int n, t;
string str;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> str;
        for (auto& s : str) {
            for (int i = 0; i < n; ++i) {
                cout << s;
            }
        }
        cout << '\n';
    }

    return 0;
}