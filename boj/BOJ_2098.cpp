/*
	출처 : https://js1jj2sk3.tistory.com/51
*/
#include <bits/stdc++.h>

using namespace std;

int n, all;
int cost[16][16];
int dp[16][1 << 16];

int dfs(int cur, int stat)
{
        if (stat == all) {
                if (cost[cur][0] == 0)
                        return 100000000;
                else
                        return cost[cur][0];
        }
        int& ref = dp[cur][stat];
        if (ref != 0)
                return ref;

        int m = INT_MAX - 10000000;
        for (int i = 1; i < n; ++i) {
                if (((stat & (1 << i)) == 0) && (cost[cur][i] != 0)) // 이전에 방문하지 않았으며 자기자신을 방문하는 것이 아니라면
                        m = min(m, dfs(i, (stat | (1 << i))) + cost[cur][i]);
        }

        return ref = m;
}

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        memset(dp, 0, sizeof(dp));
        cin >> n;

        all = (1 << n) - 1;
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        cin >> cost[i][j];
                }
        }
        cout << dfs(0, 1) << '\n';

        return 0;
}
