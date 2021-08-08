#include <iostream>
#include <vector>

using namespace std;

int n, l, d;
vector<bool> info(4000000, false);

int main()
{
    cin >> n >> l >> d;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            info[(l + 5) * i + j] = true;
        }
    }
    for (int i = 0;; ++i) {
        if (info[i * d] == false) {
            cout << i * d << '\n';

            break;
        }
    }

    return 0;
}