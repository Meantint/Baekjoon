#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i < dp.size(); i++) {
		for (int j = 1; j < dp[0].size(); j++) {
			cin >> dp[i][j];
		}
	}
	for (int i = 1; i < dp.size(); i++) {
		for (int j = 1; j < dp[0].size(); j++) {
			if (i == 1) {
				dp[i][j] += dp[i][j - 1];
			}
			else if (j == 1) {
				dp[i][j] += dp[i - 1][j];
			}
			else {
				dp[i][j] += max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	cout << dp[n][m] << endl;

	return 0;
}
