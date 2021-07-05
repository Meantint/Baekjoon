#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> dp(n + 1, vector<int>(2, 0));
	for (int i = 1; i < dp.size(); i++) {
		cin >> dp[i][1];
	}
	dp[0][0] = 0;
	dp[1][0] = 1;
	for (int i = 2; i < dp.size(); i++) {
		for (int j = 1; j < i; j++) {
			if (dp[j][1] < dp[i][1]) {
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
			}
			else {
				dp[i][0] = max(1, dp[i][0]);
			}
		}
	}

	int maxNum = 0;
	for (int i = 1; i < dp.size(); i++) {
		maxNum = max(maxNum, dp[i][0]);
	}
	cout << maxNum << endl;

	return 0;
}
