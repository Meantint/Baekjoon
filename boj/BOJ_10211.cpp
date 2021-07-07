#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, t;
vector<int> arr;
vector<int> dp;  // dp[i] : arr[i]를 포함했을 때의 최대 값

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        arr = vector<int>(n);
        dp = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        dp[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        }
        int answer = -2112345678;
        for (int i = 0; i < n; ++i) {
            answer = max(answer, dp[i]);
        }
        cout << answer << '\n';
    }

    return 0;
}