#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int tc, n;

int gcd(int x, int y)
{
    if (x % y == 0) {
        return y;
    }
    return gcd(y, x % y);
}

int main()
{
    cin >> tc;
    while (tc--) {
        cin >> n;

        ll ret = 0;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ret += (ll)gcd(arr[i], arr[j]);
            }
        }

        cout << ret << '\n';
    }

    return 0;
}