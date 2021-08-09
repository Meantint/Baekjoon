#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
int target;

int main()
{
    cin >> n;
    arr.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    cin >> target;

    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; ++i) {
        if (arr[i - 1] == target || arr[i] == target) {
            cout << 0 << '\n';
            break;
        }
        else if (arr[i - 1] < target && target < arr[i]) {
            cout << (target - arr[i - 1]) * (arr[i] - target) - 1 << '\n';
            break;
        }
    }

    return 0;
}