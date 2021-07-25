#include <iostream>
#include <string>

using namespace std;

int n;
string str;

int main()
{
    cin >> n >> str;

    int couple_count = 0;
    for (auto ch : str) {
        if (ch == 'L') {
            ++couple_count;
        }
    }

    if (couple_count == 0) {
        cout << n << '\n';
    }
    else {
        cout << n - ((couple_count / 2) - 1) << '\n';
    }

    return 0;
}