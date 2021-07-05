#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int cost[22];
int value[22];
int dp[22][102];

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) 	cin >> cost[i];
	for (int i = 1; i <= N; i++) 	cin >> value[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 99; j++) 		dp[i][j] = dp[i - 1][j];
		for (int j = cost[i]; j <= 99; j++) 	dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + value[i]);
	}
	cout << dp[N][99] << endl;
	return 0;
}
