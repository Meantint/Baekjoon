// Kruskal 이용

#include <algorithm>
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

// union_find
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

// 정점의 개수
int V;
// 그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<vector<PII>> adj;

int kruskal(vector<PII>& selected)
{
    int ret = 0;
    selected.clear();
    // (가중치, (정점 1, 정점 2))의 목록을 얻는다.
    vector<pair<int, PII>> edges;
    for (int u = 0; u < V; ++u) {
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    }
    // 가중치 순으로 정렬
    sort(edges.begin(), edges.end());
    // 처음엔 모든 정점이 서로 분리되어 있다.
    DisjointSet sets(V);
    for (int i = 0; i < edges.size(); ++i) {
        // 간선 (u, v)를 검사한다.
        int cost = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        // 이미 u와 v가 연결되어 있을 경우 무시한다.
        if (sets.find(u) == sets.find(v)) continue;
        // 이 둘을 합친다.
        sets.merge(u, v);
        selected.push_back(make_pair(u, v));
        ret += cost;
    }
    return ret;
}

int main()
{
    cin >> V;
    adj.resize(V);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b, dist;
        cin >> a >> b >> dist;
        adj[a - 1].push_back(make_pair(b - 1, dist));
        adj[b - 1].push_back(make_pair(a - 1, dist));
    }

    vector<PII> vec;
    cout << kruskal(vec) << '\n';

    return 0;
}

// Test Case
// 6 10
// 0 1 13
// 0 2 10
// 0 3 7
// 1 2 3
// 1 4 4
// 2 3 5
// 2 4 5
// 2 5 5
// 3 5 6
// 4 5 6

// Result
// 24
// Edge #1 : (1, 2)
// Edge #2 : (1, 4)
// Edge #3 : (2, 3)
// Edge #4 : (2, 5)
// Edge #5 : (0, 3)