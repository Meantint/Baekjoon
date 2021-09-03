#include <iostream>
#include <vector>

using namespace std;

int n;
int ret = -1;

int main()
{
    cin >> n;

    int div3 = 0;
    while (0 <= n) {
        if (n % 5 == 0) {
            ret = div3 + n / 5;
            break;
        }
        else {
            n -= 3;
            ++div3;
        }
    }

    cout << ret << '\n';

    return 0;
}