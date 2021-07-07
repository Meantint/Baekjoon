#include <iostream>

using namespace std;

int a, b;

int main()
{
    cin >> a >> b;

    if (a > b) {
        cout << '>' << '\n';
    }
    else if (a == b) {
        cout << "==" << '\n';
    }
    else {
        cout << '<' << '\n';
    }

    return 0;
}