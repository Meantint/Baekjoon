#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j != i; --j) {
            cout << ' ';
        }
        for (int j = i; j >= 0; --j) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}