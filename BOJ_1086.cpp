#include <bits/stdc++.h>

using namespace std;

int n, k;
int all;
string st[15];
long long dp[15][(1 << 15)];
long long n1, n2 = 1;

bool isDiv(string s){
	int tmp = 0;

	int size = s.size();
	for(int i = 0; i < size; ++i){
		tmp *= 10;
		tmp += (st[cur][i] - '0');
		tmp %= k;
	}
	
	return !tmp;
}

long long dfs(int cur, int stat, string tmp){
	if(stat == all){
		return 0;
	}

	for(int i = 0; i < n; ++i){
		if((stat & (1 << i)) == 0){
			if(isDiv(tmp + st[cur])){

			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, 0, sizeof(dp));
	cin >> n;
	all = (1 << n) - 1;
	for(int i = 1; i < n + 1; ++i){
		n2 *= i;
	}
	for(int i = 0; i < n; ++i){
		cin >> st[i];
	}
	cin >> k;

}
