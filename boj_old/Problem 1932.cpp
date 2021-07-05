#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> dp(n, vector<int> (n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> dp[i][j];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] += dp[i - 1][j];
			}
			else if (j == i) {
				dp[i][j] += dp[i - 1][j - 1];
			}
			else {
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}

	int maxNum = dp[n - 1][0];
	for (int i = 1; i < dp[n - 1].size(); i++) {
		maxNum = max(maxNum, dp[n - 1][i]);
	}

	cout << maxNum << endl;

	return 0;
}
