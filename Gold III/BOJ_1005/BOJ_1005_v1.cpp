#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int tc;
int n, k, w;
int answer;
vector<int> time_cost;
vector<int> ind;
vector<int> current_cost;
vector<vector<int>> adj;

void solve()
{
    answer = 0;

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (ind[i] == 0) {
            q.push(i);
            // current_cost[i] = time_cost[i];
        }
    }

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        current_cost[current_node] += time_cost[current_node];

        // cout << current_node << ", " << current_cost[current_node] << '\n';

        if (current_node == w) {
            answer = current_cost[current_node];
            return;
        }

        int next_size = adj[current_node].size();
        for (int i = 0; i < next_size; ++i) {
            int next_node = adj[current_node][i];
            if (current_cost[current_node] > current_cost[next_node]) {
                current_cost[next_node] = current_cost[current_node];
            }

            --ind[next_node];
            if (ind[next_node] == 0) {
                q.push(next_node);
            }
        }
    }
}

int main()
{
    cin >> tc;
    for (int t = 0; t < tc; ++t) {
        adj = vector<vector<int>>(0, vector<int>(0));

        cin >> n >> k;
        time_cost = ind = current_cost = vector<int>(n, 0);
        adj.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> time_cost[i];
        }
        for (int i = 0; i < k; ++i) {
            int v1, v2;
            cin >> v1 >> v2;

            adj[v1 - 1].push_back(v2 - 1);
            ++ind[v2 - 1];
        }
        cin >> w;
        --w;

        solve();

        cout << answer << '\n';
    }

    return 0;
}