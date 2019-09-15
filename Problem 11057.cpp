#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> dp(n + 1, vector<int>(10, 0));
	dp[1] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][j] += dp[i - 1][k];
			}
			dp[i][j] %= 10007;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
	}

	cout << sum % 10007 << endl;

	return 0;
}
