#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
int n, m;
int answer = 0;

void dfs(int start, vector<bool>& isVisited)
{
    if (isVisited[start]) return;
    isVisited[start] = true;
    for (int i = 0; i < adj[start].size(); ++i) {
        dfs(adj[start][i], isVisited);
    }
}

void dfsAll()
{
    vector<bool> isVisited(n, false);
    for (int i = 0; i < n; ++i) {
        // 방문한 적이 없으면
        if (!isVisited[i]) {
            dfs(i, isVisited);
            ++answer;
        }
    }
}

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
    // cout << "isGood\n";
    dfsAll();
    cout << answer << '\n';

    return 0;
}