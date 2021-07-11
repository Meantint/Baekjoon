// kruskal algorithm

#include <algorithm>
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, m;
vector<vector<PII>> adj;

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 1)
    {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    // u가 속한 트리의 루트의 번호를 반환
    int find(int u)
    {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    // u가 속한 트리와 v가 속한 트리를 합친다.
    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v]) ++rank[v];
    }
};

int kruskal(vector<int>& selected)
{
    int ret = 0;
    selected.clear();
    // (가중치, (정점 1, 정점 2))의 목록을 얻는다.
    vector<pair<int, PII>> edges;
    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    }
    // 가중치 순으로 정렬
    sort(edges.begin(), edges.end());
    // 처음엔 모든 정점이 서로 분리되어 있다.
    DisjointSet sets(n);
    for (int i = 0; i < edges.size(); ++i) {
        // 간선 (u, v)를 검사한다.
        int cost = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        // 이미 u와 v가 연결되어 있을 경우 무시한다.
        if (sets.find(u) == sets.find(v)) continue;
        // 이 둘을 합친다.
        sets.merge(u, v);
        selected.push_back(cost);
        ret += cost;
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;

        adj[v1 - 1].push_back(make_pair(v2 - 1, dist));
        adj[v2 - 1].push_back(make_pair(v1 - 1, dist));
    }

    vector<int> savLen;
    int answer = kruskal(savLen);
    int maxLen = -1;
    for (int i = 0; i < savLen.size(); ++i) {
        maxLen = max(maxLen, savLen[i]);
    }
    cout << answer - maxLen << '\n';

    return 0;
}