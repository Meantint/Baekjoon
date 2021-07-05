#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> arr(n, 0);
	for (int i = 0; i < arr.size(); i++) {
		cin >> arr[i];
	}

	vector<int> dp(k + 1, 0);
	dp[arr[0]] = 1;
	for (int i = 2 * arr[0]; i < dp.size(); i += arr[0]) {
		dp[i] = dp[i - arr[0]] + 1;
	}
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] > k) continue;
		dp[arr[i]] = 1;
		for (int j = arr[i] + 1; j < dp.size(); j++) {
			if (dp[j - arr[i]] == 0)	continue;
			else if (dp[j] == 0)	dp[j] = dp[j - arr[i]] + 1;
			else dp[j] = min(dp[j - arr[i]] + 1, dp[j]);
		}
	}
	if (dp[k] == 0) {
		cout << "-1" << endl;
		
		return 0;
	}
	cout << dp[k] << endl;

	return 0;
}
