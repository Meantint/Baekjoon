#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> dp(n, 0);
	for (int i = 0; i < dp.size(); i++) {
		scanf("%d", &dp[i]);
	}
	sort(dp.begin(), dp.end());

	for (int i = 0; i < dp.size(); i++) {
		cout << dp[i] << '\n';
	}
}
