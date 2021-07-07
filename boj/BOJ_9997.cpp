#include <bits/stdc++.h>

using namespace std;

int n;
int all = (1 << 26) - 1;
int answer = 0;
string st[25];

void dfs(int cur, int stat)
{
        if (stat == all) {
                answer += pow(2, n - cur);
                return;
        }
        if (cur == n) {
                return;
        }

        int cp_stat = stat;
        int size = st[cur].size();
        for (int i = 0; i < size; ++i) {
                cp_stat |= (1 << (st[cur][i] - 'a'));
        }

        dfs(++cur, cp_stat);
        dfs(cur, stat);
}

int main()
{
        cin >> n;

        for (int i = 0; i < n; ++i) {
                cin >> st[i];
        }
        dfs(0, 0);
        cout << answer << '\n';

        return 0;
}
