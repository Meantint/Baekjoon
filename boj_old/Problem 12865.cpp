#include <iostream>
#include <vector>
#include <algorithm>

#define PII pair<int, int>

using namespace std;

int N, K, W, V;
vector<PII> v;
vector<vector<int>> dp;

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		int num1, num2;
		cin >> num1 >> num2;
		v.push_back(PII(num1, num2));

		vector<int> push(K + 1, 0);
		dp.push_back(push);
	}

	// dp[n][k] : 0 ~ n번까지 사용하고,
	//	      k 만큼 썼을 때 얻을 수 있는 이윤의 최대치
	for (int i = 0; i < v.size(); ++i) {
		int idx = v[i].first;
		dp[i][idx] = v[i].second;
		while (++idx < dp[0].size()) {
			dp[i][idx] = v[i].second;
		}
	}
#if 0
	for (int i = 0; i < dp.size(); ++i) {
		for (int j = 0; j < dp[0].size(); ++j) {
			cout << dp[i][j] << ' ';
		}
		cout << "\n";
	}
#endif
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < K + 1; ++j) {
			if (j - v[i].first >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i].first] + v[i].second);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
#if 0
	for (int i = 0; i < dp.size(); ++i) {
		for (int j = 0; j < dp[0].size(); ++j) {
			cout << dp[i][j] << ' ';
		}
		cout << "\n";
	}
#endif

	cout << dp[N - 1][K] << endl;

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();

	return 0;
}
