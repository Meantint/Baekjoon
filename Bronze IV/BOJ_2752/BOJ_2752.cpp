#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr(3);

int main()
{
    for (int i = 0; i < 3; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < 3; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}