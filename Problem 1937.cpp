#include <iostream>
#include <vector>
#include <algorithm>

#define TEST 0

using namespace std;

int N;
vector<vector<int>> arr(502, vector<int>(502, 0));
vector<vector<int>> dp(502, vector<int>(502, -1));
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int dfs(int i, int j) {
	if (i < 1 || j < 1 || i > N || j > N)	return 0;
	if (dp[i][j] != -1)	return dp[i][j];			// 방문한 적이 있다면
	else {								// 방문한 적이 없다면
		for (int k = 0; k < 4; k++) {
			if (arr[i + dx[k]][j + dy[k]] > arr[i][j]) {	// 현위치 보다 대나무가 많다면
				dp[i][j] = max(dp[i][j], dfs(i + dx[k], j + dy[k]));
			}
		}
	}
	if (dp[i][j] == -1)	return dp[i][j] = 1;
	else {
		dp[i][j]++;
		return dp[i][j];
	}
}

int main()
{
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		} 
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dp[i][j] == -1)
				dfs(i, j);
		}
	}
	int max_Dp = -2;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			max_Dp = max(max_Dp, dp[i][j]);
		}
	}
#if TEST
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
#endif
	cout << max_Dp << endl;

	return 0;
}
