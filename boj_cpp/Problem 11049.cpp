#include <iostream>
#include <vector>
#include <algorithm>

#define PII pair<int, int>

using namespace std;

int N;
int dp[502][502];
PII arr[502];

void solve() {
	for (int i = N; i > 0; --i) {
		for (int j = i; j <= N; ++j) {
			//dp[i][j] = 2147483647;
			if (i == j) {
				dp[i][j] = 0;
			}
			else {
				int k = i;
				dp[i][j] = dp[i][k] + dp[k + 1][j] + arr[i].first * arr[k].second * arr[j].second;
				for (k = i + 1; k <= j - 1; ++k) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i].first * arr[k].second * arr[j].second);
				}
			}
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}
	
	solve();
	cout << dp[1][N] << endl;

	return 0;
}
