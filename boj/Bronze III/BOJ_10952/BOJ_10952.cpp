#include <iostream>

using namespace std;

int n, a, b;

int main()
{
    while (1) {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        cout << a + b << '\n';
    }

    return 0;
}