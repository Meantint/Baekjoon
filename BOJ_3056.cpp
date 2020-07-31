// 메모이제이션을 해야 맞음 ! 안해서 틀림 ㅠ

/*#include <bits/stdc++.h>


#define PDI pair<double, int>

using namespace std;

int n;
double board[20][20];
PDI dp[20][20];
double answer = -1;

void dfs(int cur){
	if(cur == n){
		for(int i = 0; i < n; ++i){
			answer = max(answer, dp[n - 1][i].first);
		}
		return;
	}

	for(int i = 0; i < n; ++i){
		double tmp = -1.0;
		for(int j = 0; j < n; ++j){
			if((dp[cur - 1][j].second & (1 << i)) == 0){
				tmp = max(tmp, dp[cur - 1][j].first);
			}
		}
		dp[cur][i].first = tmp * board[cur][i];
	}
	dfs(
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, 0, sizeof(dp));
	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> board[i][j];
		}
	}
	for(int i = 0; i < n; ++i){
		dp[0][i].first = 0.01 * board[0][i];
		dp[0][i].second = (1 << i);
	}

	cout << fixed;
	cout.precision(6);
	cout << answer * (double)100 << '\n';

	return 0;
}*/

#include <bits/stdc++.h>

using namespace std;

int n;

double cache[(1 << 20)];
double board[20][20];
double answer = -1;

double dfs(int cur, int stat){
	if(cur == n){
		return 1.0;
	}

	double &ret = cache[stat];
	if(ret != -1.0)
		return ret;
	ret = 0.0;

	for(int i = 0; i < n; ++i){
		if((stat & (1 << i)) == 0){
			stat |= (1 << i);
			ret = max(ret, board[cur][i] * dfs(cur + 1, stat));
			stat &= ~(1 << i);
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i = 0; i < (1 << 20); ++i){
		cache[i] = -1;
	}
	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> board[i][j];
			board[i][j] /= 100.0;
		}
	}
	answer = dfs(0, 0);

	cout << fixed;
	cout.precision(6);
	cout << answer * 100.0 << '\n';

	return 0;
}

