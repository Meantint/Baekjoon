#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> dp(n + 1, vector<int>(10, 0));
	dp[1] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	for (int i = 2; i < dp.size(); i++) {
		dp[i][0] = dp[i - 1][1] % 1000000000;
		for (int j = 1; j < dp[0].size() - 1; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
		dp[i][9] = dp[i - 1][8] % 1000000000;
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
		sum %= 1000000000;
	}
	cout << sum << endl;

	return 0;
}
