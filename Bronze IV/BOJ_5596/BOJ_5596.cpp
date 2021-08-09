#include <iostream>

using namespace std;

int main()
{
    int s1 = 0, s2 = 0;
    int v;

    for (int i = 0; i < 4; ++i) {
        cin >> v;
        s1 += v;
    }
    for (int i = 0; i < 4; ++i) {
        cin >> v;
        s2 += v;
    }

    if (s1 > s2) {
        cout << s1 << '\n';
    }
    else {
        cout << s2 << '\n';
    }

    return 0;
}