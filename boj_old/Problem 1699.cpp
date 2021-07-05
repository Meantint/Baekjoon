#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> dp(n + 1, 100000);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < dp.size(); i++) {
		for (int j = 1; j * j <= i; j++) {
			if (j * j == i) {
				dp[i] = 1;
			}
			dp[i] = min(dp[j * j] + dp[i - j * j], dp[i]);
		}
	}
	cout << dp[n] << endl;

	return 0;
}
