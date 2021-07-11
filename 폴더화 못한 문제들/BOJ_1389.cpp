#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>
#define INF 2112345678

using namespace std;

int n, m;
vector<vector<int>> adj;

int main()
{
    cin >> n >> m;
    adj.resize(n);

    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1 - 1].push_back(v2 - 1);
        adj[v2 - 1].push_back(v1 - 1);
    }
    int minAnswer = INF;
    int answer = INF;
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        vector<bool> isVisited(n, false);
        queue<PII> q;
        q.push(make_pair(i, 0));

        while (!q.empty()) {
            int cur = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (isVisited[cur]) continue;
            else {
                tmp += dist;
                isVisited[cur] = true;
            }
            for (int i = 0; i < adj[cur].size(); ++i) {
                q.push(make_pair(adj[cur][i], dist + 1));
            }
        }
        if (minAnswer > tmp) {
            answer = i + 1;
            minAnswer = tmp;
        }
    }
    cout << answer << '\n';

    return 0;
}