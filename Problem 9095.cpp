#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> dp(11, 0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
  
        // dp[i]는 dp[i - 1], dp[i - 2], dp[i - 3]에서 각각 1, 2, 3을 더한 것과 같기 때문에
        // dp[i]의 모든 경우의 수가 다 나오게 된다.
	for (int i = 4; i < dp.size(); i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;

		cout << dp[num] << endl;
	}

	return 0;
}
