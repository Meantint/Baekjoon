#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n; 
		cin >> n;

		vector<vector<int>> dp(2, vector<int>(n + 1, 0));
		for (int j = 0; j < dp.size(); j++) {
			for (int k = 1; k < dp[0].size(); k++) {
				cin >> dp[j][k];
			}
		}
		dp[0][2] += dp[1][1];
		dp[1][2] += dp[0][1];
		for (int j = 3; j < dp[0].size(); j++) {
			dp[0][j] += max(dp[1][j - 1], max(dp[0][j - 2], dp[1][j - 2]));
			dp[1][j] += max(dp[0][j - 1], max(dp[0][j - 2], dp[1][j - 2]));
		}

		cout << max(dp[0][n], dp[1][n]) << endl;
	}

	return 0;
}
