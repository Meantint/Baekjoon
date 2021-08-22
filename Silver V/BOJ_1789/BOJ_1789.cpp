#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll s;
int answer = -1;

void solve()
{
    int low = 1, high = 1000000, mid;

    while (low <= high) {
        mid = ((low + high) >> 1);

        ll sum = (1LL) * (mid + 1) * mid / 2;

        if (sum > s) {
            high = mid - 1;
        }
        else {
            answer = mid;

            low = mid + 1;
        }
    }
}

int main()
{
    cin >> s;

    solve();

    cout << answer << '\n';

    return 0;
}