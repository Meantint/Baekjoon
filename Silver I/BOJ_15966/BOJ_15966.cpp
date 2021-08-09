#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dp(1000010, 0);
vector<int> arr;

int main()
{
    cin >> n;

    arr.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        dp[arr[i]] = dp[arr[i] - 1] + 1;
    }

    int answer = 0;
    for (int i = 1; i <= 1000000; ++i) {
        if (answer < dp[i]) {
            answer = dp[i];
        }
    }

    cout << answer << '\n';

    return 0;
}