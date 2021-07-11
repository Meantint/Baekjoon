#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> cost;
vector<int> maxTime;
vector<int> ind;

int main()
{
    cin >> n;
    adj.resize(n);
    maxTime.resize(n, 0);
    ind.resize(n, 0);

    for (int i = 0; i < n; ++i) {
        int time, num;
        cin >> time >> num;
        cost.push_back(time);
        while (num != -1) {
            adj[num - 1].push_back(i);
            ++ind[i];
            cin >> num;
        }
    }

    // for (int i = 0; i < ind.size(); ++i) {
    //     cout << cost[i] << '\n';
    // }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        if (ind[i] == 0) {
            q.push(make_pair(cost[i], i));
            maxTime[i] = cost[i];
        }
    }
    while (!q.empty()) {
        int cos = q.front().first;
        int cur = q.front().second;
        q.pop();
        // cout << cos << ", " << cur << '\n';

        for (int i = 0; i < adj[cur].size(); ++i) {
            int next = adj[cur][i];
            int nextCost = cost[next] + cos;
            if (maxTime[next] < nextCost) {
                maxTime[next] = nextCost;
            }
            --ind[next];
            if (ind[next] == 0) {
                q.push(make_pair(maxTime[next], next));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << maxTime[i] << '\n';
    }

    return 0;
}