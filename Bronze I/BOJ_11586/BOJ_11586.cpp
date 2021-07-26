#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, k;
vector<string> image;

int main()
{
    cin >> n;
    image.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> image[i];
    }
    cin >> k;

    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << image[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
    else if (k == 2) {
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                cout << image[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
    else {
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                cout << image[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}