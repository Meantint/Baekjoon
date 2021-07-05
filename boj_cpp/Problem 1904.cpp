#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < dp.size(); i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 15746;
	}

	cout << dp[n] << endl;

	return 0;
}
