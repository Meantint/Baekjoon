#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n + 1, 0);
	for (int i = 1; i < arr.size(); i++) {
		cin >> arr[i];
	}

	// dp[i] : arr[i]를 포함했을 때의 최댓값
	vector<int> dp(n + 1, 0);
	dp[1] = arr[1];
	int maxNum = arr[1];
	for (int i = 2; i < dp.size(); i++) {
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (dp[i] < dp[j] + arr[i]) {
					dp[i] = dp[j] + arr[i];
				}
			}
		}
		if (dp[i] == 0) {
			dp[i] = arr[i];
		}
		if (maxNum < dp[i])	maxNum = dp[i];
	}

	cout << maxNum << endl;

	return 0;
}
