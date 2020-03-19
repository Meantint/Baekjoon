#include <iostream>

using namespace std;

int N;
int map[100][100];
long long dp[100][100];

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

long long dfs(int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= N)	return 0;
	if (i == N - 1 && j == N - 1)	return 1;
	if (map[i][j] == 0)	return 0;

	if (dp[i][j] == -1)	return 0;
	else if (dp[i][j] > 0)	return dp[i][j];
	else {
		for (int k = 0; k < 2; k++) {
			int moveX = dx[k] * map[i][j];
			int moveY = dy[k] * map[i][j];
			dp[i][j] += dfs(i + moveX, j + moveY);
		}
		if (dp[i][j] == 0) {	// i, j에서 갈 수 있는 곳이 한군데도 없으면
			dp[i][j] = -1;
			return 0;
		}
		return dp[i][j];
	}
}

int main()
{
	cin >> N;
	dp[N - 1][N - 1] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	cout << dfs(0, 0) << endl;

	return 0;
}
