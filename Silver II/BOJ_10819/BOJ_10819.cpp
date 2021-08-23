#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int main()
{
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int answer = 0;

    do {
        int ret = 0;
        for (int i = 1; i < n; ++i) {
            ret += abs(arr[i] - arr[i - 1]);
        }
        if (answer < ret) {
            answer = ret;
        }
    } while (next_permutation(arr.begin(), arr.end()));

    cout << answer << '\n';

    return 0;
}