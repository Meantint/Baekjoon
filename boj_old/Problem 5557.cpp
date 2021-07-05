#include <iostream>

using namespace std;

long long dp[110][30];
int arr[110];
int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}

	dp[1][arr[1]] = 1;
	for (int i = 1; i < N - 1; ++i) {
		for (int j = 0; j <= 20; ++j) {
			if (dp[i][j] != 0) {
				if(j + arr[i+1] <= 20)
					dp[i + 1][j + arr[i + 1]] += dp[i][j];
				if (j - arr[i + 1] >= 0)
					dp[i + 1][j - arr[i + 1]] += dp[i][j];
			}
		}
	}

	cout << dp[N - 1][arr[N]] << endl;

	return 0;
}
