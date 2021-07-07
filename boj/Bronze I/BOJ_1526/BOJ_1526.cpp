#include <iostream>
#include <vector>

using namespace std;

int n, answer;
vector<bool> num(10, false);

void solve()
{
    for (int i = n; i > 3; --i) {
        int temp = i;

        bool isPerfect = true;
        while (temp != 0) {
            if (num[temp % 10]) {
                temp /= 10;
            }
            else {
                isPerfect = false;
                break;
            }
        }
        if (isPerfect) {
            answer = i;
            break;
        }
    }
}

int main()
{
    cin >> n;

    num[4] = num[7] = true;
    solve();

    cout << answer << '\n';

    return 0;
}