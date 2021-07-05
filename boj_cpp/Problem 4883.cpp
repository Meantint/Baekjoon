#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100000, INF = 2140000;
int graph[N + 5][3];
int dp[N + 5][3];
int n;

int get_Dp(int i, int j) {
	if (i == 0 && j == 1)	return dp[i][j] = graph[i][j];
	if (i == 0 && j == 2)	return dp[i][j] = graph[i][j - 1] + graph[i][j];
	if (i <= 0 || j > 2 || j < 0)	return INF;
	if (dp[i][j] != INF) return dp[i][j];	// dp가 모두 INF로 초기화 되어있기 때문에
						// dp[i][j]가 INF면 방문한 적이 없는 것으로 볼 수 있음
						// dp[i][j]가 INF가 아니면 방문한 적이 있으므로
						// dp[i][j]를 return함.
	return dp[i][j] = min({ get_Dp(i - 1, j - 1), get_Dp(i - 1, j), get_Dp(i - 1, j + 1), get_Dp(i, j - 1) }) + graph[i][j];
}

int main()
{
	int cnt = 1;
	for (int i = 0; true; i++) {
		cin >> n;

		if (n == 0)	break;

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 3; k++) {
				dp[j][k] = INF;
				cin >> graph[j][k];
			}
		}
		cout << cnt << ". " << get_Dp(n - 1, 1) << endl;
		cnt++;
	}
	return 0;
}
