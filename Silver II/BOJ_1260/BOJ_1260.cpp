#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, v;
vector<vector<int>> adj;

void DFS(int curNode, vector<bool>& isVisited)
{
    cout << curNode << ' ';
    isVisited[curNode] = true;

    int size = adj[curNode].size();
    for (int i = 0; i < size; ++i) {
        int nextNode = adj[curNode][i];
        if (!isVisited[nextNode]) {
            DFS(nextNode, isVisited);
        }
    }
}

void BFS(int startNode)
{
    vector<bool> isVisited(n + 1, false);
    queue<int> q;

    q.push(startNode);
    isVisited[startNode] = true;

    while (!q.empty()) {
        int curNode = q.front();
        q.pop();

        cout << curNode << ' ';

        int size = adj[curNode].size();
        for (int i = 0; i < size; ++i) {
            int nextNode = adj[curNode][i];

            if (!isVisited[nextNode]) {
                isVisited[nextNode] = true;
                q.push(nextNode);
            }
        }
    }
    cout << '\n';
}

int main()
{
    cin >> n >> m >> v;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<bool> isVisited(n + 1, false);
    DFS(v, isVisited);
    cout << '\n';
    BFS(v);

    return 0;
}