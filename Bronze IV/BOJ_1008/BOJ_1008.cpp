#include <iostream>

using namespace std;

double a, b;

int main()
{
    cin >> a >> b;

    cout << fixed;
    cout.precision(9);
    cout << a / b << '\n';

    return 0;
}