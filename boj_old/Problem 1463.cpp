#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> dp(n + 3, 0);

	dp[1] = 0;          // 1일 때는 아무런 행동을 하지 않아도 된다.
	dp[2] = dp[3] = 1;  // 2, 3일 때는 1회의 비용이 든다.
	if (n < 4) {        // n이 1, 2, 3 중 하나일 때 반환하고 종료한다.
		cout << dp[n] << endl;
		return dp[n];
	}

	for (int i = 4; i < n + 1; i++) {
		if (i % 6 == 0)             // i가 3과 2로 모두 나누어 떨어질 때
			dp[i] = min(dp[i / 3], min(dp[i / 2], dp[i - 1])) + 1;	// 3가지 case 중 가장 비용이 적게 드는 것 + 1회 추가
		else if (i % 3 == 0)        // i가 3으로 나누어 떨어지지만 2로는 나누어 떨어지지 않을 때
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		else if (i % 2 == 0)        // i가 2로 나누어 떨어지지만 3으로는 나누어 떨어지지 않을 때
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		else                        // i가 3과 2로 나누어 떨어지지 않을 때
			dp[i] = dp[i - 1] + 1;
	}
	cout << dp[n] << endl;

	return 0;
}
