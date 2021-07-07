#include <bits/stdc++.h>

using namespace std;

int main()
{
        int n;
        cin >> n;

        int minDp[2][3];
        int maxDp[2][3];
        int arr[1][3];
        cin >> arr[0][0] >> arr[0][1] >> arr[0][2];
        minDp[0][0] = maxDp[0][0] = arr[0][0];
        minDp[0][1] = maxDp[0][1] = arr[0][1];
        minDp[0][2] = maxDp[0][2] = arr[0][2];

        for (int i = 1; i < n; ++i) {
                cin >> arr[0][0] >> arr[0][1] >> arr[0][2];
                minDp[i % 2][0] = min(minDp[(i - 1) % 2][0], minDp[(i - 1) % 2][1]) + arr[0][0];
                minDp[i % 2][1] = min({ minDp[(i - 1) % 2][0], minDp[(i - 1) % 2][1], minDp[(i - 1) % 2][2] }) + arr[0][1];
                minDp[i % 2][2] = min(minDp[(i - 1) % 2][1], minDp[(i - 1) % 2][2]) + arr[0][2];
                maxDp[i % 2][0] = max(maxDp[(i - 1) % 2][0], maxDp[(i - 1) % 2][1]) + arr[0][0];
                maxDp[i % 2][1] = max({ maxDp[(i - 1) % 2][0], maxDp[(i - 1) % 2][1], maxDp[(i - 1) % 2][2] }) + arr[0][1];
                maxDp[i % 2][2] = max(maxDp[(i - 1) % 2][1], maxDp[(i - 1) % 2][2]) + arr[0][2];
        }

        cout << max({ maxDp[(n - 1) % 2][0], maxDp[(n - 1) % 2][1], maxDp[(n - 1) % 2][2] }) << ' ' << min({ minDp[(n - 1) % 2][0], minDp[(n - 1) % 2][1], minDp[(n - 1) % 2][2] }) << '\n';

        return 0;
}
