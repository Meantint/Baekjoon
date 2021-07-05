#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
char arr[1002][1002];
vector<vector<int>> dp(1002, vector<int>(1002, 0));

void search(int i, int j) {
	if (i < 1 || i > N || j < 1 || j > M)	return;
	dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == '1')
				search(i, j);
			else {
				dp[i][j] = 0;
			}
		}
	}

	int max_Value = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			max_Value = max(max_Value, dp[i][j]);
		}
	}

	cout << max_Value * max_Value << endl;

	return 0;
}
