#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> t(n + 1, 0);
	vector<int> p(n + 1, 0);
	for (int i = 1; i < t.size(); i++) {
		cin >> t[i] >> p[i];
	}

	int maxNum = 0;
	vector<int> dp(n + 1, 0);
	for (int i = 1; i < dp.size(); i++) {
		if (t[i] == 1) {
			dp[i] = max(dp[i], dp[i - 1] + p[i]);
			maxNum = max(maxNum, dp[i]);
		}
		else {
			// 최댓값을 이어나가야 하므로 dp[i]가 0이면 이전의 최댓값을 저장한다.
			dp[i] = max(dp[i - 1], dp[i]);
			if (i + t[i] - 1 < dp.size()) {
				dp[i + t[i] - 1] = max(dp[i - 1] + p[i], dp[i + t[i] - 1]);
				maxNum = max(maxNum, dp[i + t[i] - 1]);
			}
			else continue;
		}
	}

	cout << dp[n] << endl;

	return 0;
}
