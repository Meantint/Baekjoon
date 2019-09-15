#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> dp[i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i / 2; j++) {
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
		}
	}

	cout << dp[n] << endl;

	return 0;
}
