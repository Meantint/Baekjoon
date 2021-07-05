#include <iostream>
#include <string.h>

using namespace std;

int N;
int longDp;
int arr[202];
int dp[202];

void solve() {
	dp[0] = arr[0];
	longDp = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (dp[j] == -1) {
				dp[j] = arr[i];
				longDp++;
				break;
			}
			if (dp[j] <= arr[i])	continue;
			else {	// dp[j] > arr[i]
				dp[j] = arr[i];
				break;
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	
	memset(dp, -1, sizeof(dp));
	solve();
	cout << N - longDp << endl;

	return 0;
}