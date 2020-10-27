#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, m;
PII ans;
vector<vector<int>> adj;
vector<bool> isCheck;

int main()
{
    cin >> n;
    adj.resize(n);
    isCheck.resize(n, false);
    cin >> ans.first >> ans.second;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1 - 1].push_back(v2 - 1);
        adj[v2 - 1].push_back(v1 - 1);
    }

    queue<PII> q;
    q.push(make_pair(0, ans.first - 1));
    bool isFind = false;
    while (!q.empty()) {
        int dist = q.front().first;
        int cur = q.front().second;
        q.pop();

        if (cur == ans.second - 1) {
            cout << dist << '\n';
            isFind = true;
            break;
        }
        if (isCheck[cur]) continue;
        isCheck[cur] = true;
        for (int i = 0; i < adj[cur].size(); ++i) {
            int next = adj[cur][i];
            q.push(make_pair(dist + 1, next));
        }
    }
    if (!isFind) {
        cout << "-1\n";
    }

    return 0;
}