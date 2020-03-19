#include <iostream>
#include <vector>

using namespace std;

int N, M;
int map[500][500];
int dp[500][500];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int dfs(int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= M)	return 0;
	if (i == N - 1 && j == M - 1)			return dp[N - 1][M - 1];

	if (dp[i][j] == -1)		// 이미 방문한 곳이면서 루트가 더 이상 없을 경우 0을 반환한다.
		return 0;
	else if (dp[i][j] > 0)	// 이미 방문한 곳이면서 루트가 존재할 경우 그 값을 가져온다.
		return dp[i][j];
	// else
	for (int k = 0; k < 4; k++) {
		if(map[i][j] > map[i + dx[k]][j + dy[k]])
			dp[i][j] += dfs(i + dx[k], j + dy[k]);
	}
	if (dp[i][j] == 0) {
		dp[i][j] = -1;
		return 0;
	}

	return dp[i][j];
}

int main()
{
	// memset(dp, -1, sizeof(dp));

	cin >> N >> M;

	dp[N - 1][M - 1] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	cout << dfs(0, 0) << endl;

	return 0;
}
