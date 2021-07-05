#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	vector<int> score(T + 1, 0);				// 점수를 저장하는 배열
	vector<vector<int>> dp(T + 1, vector<int>(3, 0));	// i 번째의 최대 점수를 구하기 위한 dp 배열

	for (int i = 1; i < T + 1; i++)
		cin >> score[i];
	dp[0][1] = dp[0][2] = 0;
	dp[1][1] = score[1];
	dp[1][2] = 0;

	for (int i = 2; i < T + 1; i++) {
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];	// 밟은 계단이 첫 번째 계단인 경우
		dp[i][2] = dp[i - 1][1] + score[i];			// 밟은 계단이 두 번째 계단인 경우
	}

	cout << max(dp[T][1], dp[T][2]) << endl;

	return 0;
}
