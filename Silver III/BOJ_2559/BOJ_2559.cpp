#include <iostream>
#include <vector>

using namespace std;

int n, k;
int answer;
vector<int> arr;

void solve()
{
    int temp = 0;

    answer = 0;

    for (int i = 0; i < k; ++i) {
        temp += arr[i];
    }
    answer = temp;

    for (int i = k; i < n; ++i) {
        temp += arr[i];
        temp -= arr[i - k];

        if (answer < temp) {
            answer = temp;
        }
    }
}

int main()
{
    cin >> n >> k;
    arr.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    solve();

    cout << answer << '\n';

    return 0;
}