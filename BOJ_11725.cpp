#include <iostream>
#include <vector>

using namespace std;

int v;
vector<vector<int>> adj;
// vector<bool> isVisited;

void find(int cur, vector<int>& parent)
{
    // 이미 방문했었다면
    // if (isVisited[cur]) return;
    // isVisited[cur] = true;

    for (int there = 0; there < adj[cur].size(); ++there) {
        int next = adj[cur][there];
        // 부모가 자기자신임(아직 부모를 찾지 못함)
        if (parent[next] == next) {
            parent[next] = cur;
            find(next, parent);
        }
    }
}

int main()
{
    cin >> v;
    // isVisited.resize(v, false);
    adj.resize(v);
    vector<int> parent(v);
    for (int i = 0; i < v - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1 - 1].push_back(v2 - 1);
        adj[v2 - 1].push_back(v1 - 1);
    }

    for (int i = 0; i < v; ++i) {
        parent[i] = i;
    }
    find(0, parent);
    for (int i = 1; i < v; ++i) {
        cout << parent[i] + 1 << '\n';
    }

    return 0;
}