#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> dp(1001, vector<int>(1001, 1));
	for (int i = 2; i < dp.size(); i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)	dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				dp[i][j] %= 10007;
			}
		}
	}

	int n, k;
	cin >> n >> k;
	cout << dp[n][k] << endl;

	return 0;
}
