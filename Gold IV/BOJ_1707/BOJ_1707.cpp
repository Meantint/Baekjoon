#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int tc;
int n, m;
vector<vector<int>> adj;
vector<int> check;

string solve()
{
    for (int i = 0; i < n; ++i) {
        if (check[i] == -1) {
            queue<pair<int, int>> q;  // node, 0 or 1
            q.push(make_pair(i, 0));

            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                // cout << "i, cur.first, cur.second : " << i << ", " << cur.first << ", " << cur.second << '\n';

                if (check[cur.first] == -1) {
                    check[cur.first] = cur.second;
                }
                else {
                    if (check[cur.first] != cur.second) {
                        return "NO";
                    }
                    continue;
                }

                int cur_size = adj[cur.first].size();
                for (int j = 0; j < cur_size; ++j) {
                    q.push(make_pair(adj[cur.first][j], (cur.second + 1) % 2));
                }
            }
        }
    }

    return "YES";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;

        check.clear();
        for (auto& del : adj) {
            del.clear();
        }

        check.resize(n, -1);
        adj.resize(n);

        for (int i = 0; i < m; ++i) {
            int v1, v2;
            cin >> v1 >> v2;
            adj[v1 - 1].push_back(v2 - 1);
            adj[v2 - 1].push_back(v1 - 1);
        }

        cout << solve() << '\n';
    }

    return 0;
}