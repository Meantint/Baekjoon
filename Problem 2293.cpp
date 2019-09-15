#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> arr(n + 1, 0);
	vector<int> dp(k + 1, 0);
	vector<int> newDp(k + 1, 0);
	for (int i = 1; i < arr.size(); i++) {
		cin >> arr[i];
	}
	for (int i = arr[1]; i < dp.size(); i += arr[1]) {
		dp[i]++;
	}
	for (int i = 2; i < arr.size(); i++)
	{
		int x = arr[i];
		if (x >= dp.size())	continue;	// 가치의 합 최대치보다 동전의 가치가 더 큰 경우가 있음;;
		for (int j = 1; j < x; j++) {
			newDp[j] = dp[j];
		}
		newDp[x] = dp[x] + 1;
		for (int j = x + 1; j < newDp.size(); j++) {
			newDp[j] = newDp[j - x] + dp[j];
		}

		dp = newDp;
	}
	cout << dp[k] << endl;

	return 0;
}
