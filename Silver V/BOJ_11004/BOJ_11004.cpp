#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> arr;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    arr.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cout << arr[k - 1] << '\n';

    return 0;
}