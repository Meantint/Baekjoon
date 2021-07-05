#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	vector<int> amount(T + 1, 0);
	vector<vector<int>> dp(T + 1, vector<int>(3, 0));
	for (int i = 1; i < T + 1; i++)
		cin >> amount[i];
	dp[0][1] = dp[0][2] = 0;
	dp[1][1] = amount[1];
	dp[1][2] = 0;
	int maxAmount = dp[1][1];
	if (T < 2) {  // T = 1
		cout << maxAmount << endl;
		return 0;
	}
  	// T가 2 이상이면
	dp[2][1] = amount[2];
	dp[2][2] = dp[1][1] + amount[2];
	if (max(dp[2][1], dp[2][2]) > maxAmount)
		maxAmount = max(dp[2][1], dp[2][2]);
	
	for (int i = 3; i < T + 1; i++) {
		// 계단 오르기의 방식에 두 개가 추가되었는데 (dp[i-3][1], dp[i-3][2]) 
		// 이는 두 번 연속 안 먹는 경우가 존재하기 때문
		dp[i][1] = max(max(dp[i - 2][1], dp[i - 2][2]), max(dp[i - 3][1], dp[i - 3][2])) + amount[i];
		dp[i][2] = dp[i - 1][1] + amount[i];
		if (max(dp[i][1], dp[i][2]) > maxAmount)
			maxAmount = max(dp[i][1], dp[i][2]);
	}

	cout << maxAmount << endl;

	return 0;
}
