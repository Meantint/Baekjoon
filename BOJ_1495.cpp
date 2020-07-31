#include <bits/stdc++.h>

using namespace std;

int n, s, m;
int cost[101];
int dp[101][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, 0, sizeof(dp));
	cin >> n >> s >> m;
	for(int i = 1; i < n + 1; ++i){
		cin >> cost[i];
	}
	dp[0][s] = 1;
	
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= m; ++j){
			int rv = j + cost[i];
			int lv = j - cost[i];
			if(rv <= m && dp[i - 1][rv] != 0)
				dp[i][j] = 1;
			if(lv >= 0 && dp[i - 1][lv] != 0)
				dp[i][j] = 1;
		}
	}
	
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= m; ++j){
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	
	
	int answer = -1;
	for(int i = m; i >= 0; --i){
		if(dp[n][i] != 0){
			answer = i;
		// 	cout << n << ' ' << i << '\n';
			break;
		}
	}
	cout << answer << '\n';

	return 0;
}
