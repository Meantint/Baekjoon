#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> ind;
vector<int> answer;

int main()
{
    cin >> n >> m;
    adj.resize(n);
    ind.resize(n, 0);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1 - 1].push_back(v2 - 1);
        ++ind[v2 - 1];
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        // indegree = 0 이라면
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        answer.push_back(cur + 1);

        for (int i = 0; i < adj[cur].size(); ++i) {
            int next = adj[cur][i];
            --ind[next];
            if (ind[next] == 0) {
                q.push(next);
            }
        }
    }
    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}