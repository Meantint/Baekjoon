#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int answer = 1;
	int n;
	cin >> n;

	vector<int> arr(n + 1, 0);
	vector<int> dp(n + 1, 0);
	for (int i = 1; i < arr.size(); i++) {
		cin >> arr[i];
	}
	dp[1] = 1;
	for (int i = 2; i < dp.size(); i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] == 0) {
			dp[i] = 1;
		}
		if (answer < dp[i]) {
			answer = dp[i];
		}
	}

	cout << answer << endl;

	return 0;
}
