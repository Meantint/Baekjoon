#include <iostream>
#include <vector>

using namespace std;

// n 자리 수일 때, 끝자리가 0, 1인 경우는 
// 각각 피보나치수열의 규칙으로 증가한다.
int main()
{
	int n;
	cin >> n;
	
	vector<long long> dp(n + 1, 0);
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << endl;

	return 0;
}
