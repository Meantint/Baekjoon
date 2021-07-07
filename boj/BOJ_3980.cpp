#include <bits/stdc++.h>

using namespace std;

int cost[11][11];
int answer = -1;
int all = (1 << 11) - 1;
int pt = 0;

void dfs(int cur, int stat)
{
        if (stat == all) {
                answer = max(answer, pt);
                return;
        }

        for (int i = 0; i < 11; ++i) {
                if (cost[cur][i] != 0 && ((1 << i) & stat) == 0) {
                        stat |= (1 << i);
                        pt += cost[cur][i];
                        dfs(++cur, stat);
                        --cur;
                        pt -= cost[cur][i];
                        stat -= (1 << i);
                }
        }
}

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin >> t;

        for (int tc = 0; tc < t; ++tc) {
                answer = 0;
                pt = 0;
                for (int i = 0; i < 11; ++i) {
                        for (int j = 0; j < 11; ++j) {
                                cin >> cost[i][j];
                        }
                }
                dfs(0, 0);
                cout << answer << '\n';
        }

        return 0;
}
