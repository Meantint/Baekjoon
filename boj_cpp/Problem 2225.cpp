#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	for (int i = 1; i < n + 1; i++) {
		dp[i][1] = 1;
	}
	for (int i = 1; i < k + 1; i++) {
		dp[1][i] = i;
	}
	for (int i = 2; i < dp.size(); i++) {
		for (int j = 2; j < dp[0].size(); j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= 1000000000;
		}
	}

	cout << dp[n][k] << endl;

	return 0;
}
