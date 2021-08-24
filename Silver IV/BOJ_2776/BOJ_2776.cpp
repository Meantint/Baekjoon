#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int tc, n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;

        vector<int> arr(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        cin >> m;
        for (int i = 0; i < m; ++i) {
            int target;
            cin >> target;
            int count = upper_bound(arr.begin(), arr.end(), target) - lower_bound(arr.begin(), arr.end(), target);
            if (count != 0) {
                cout << '1' << '\n';
            }
            else {
                cout << '0' << '\n';
            }
        }
    }
}