#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> dp(n);
	for (int i = 0; i < dp.size(); i++) {
		cin >> dp[i];
	}
	int max = dp[0];
	for (int i = 1; i < dp.size(); i++) {
		if (dp[i - 1] > 0 && dp[i] + dp[i - 1] > 0) {	// dp[i - 1]의 값이 0 보다 크고 
								// dp[i - 1]과 dp[i]와의 합이 0 보다 크면 참
			dp[i] = dp[i] + dp[i - 1];		
		}
		if (max < dp[i]) {
			max = dp[i];
		}
	}

	cout << max << endl;

	return 0;
}
