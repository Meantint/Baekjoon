#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<double, double>> pos;
vector<vector<pair<int, double>>> adj;
int n;

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

double kruskal(vector<pair<int, int>>& selected)
{
    double ret = 0;
    selected.clear();
    // (가중치, (정점 1, 정점 2))의 목록을 얻는다.
    vector<pair<double, pair<int, int>>> edges;
    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            double cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    }
    // 가중치 순으로 정렬
    sort(edges.begin(), edges.end());
    // 처음엔 모든 정점이 서로 분리되어 있다.
    DisjointSet sets(n);
    for (int i = 0; i < edges.size(); ++i) {
        // 간선 (u, v)를 검사한다.
        double cost = edges[i].first;
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
    cin >> n;
    adj = vector<vector<pair<int, double>>>(n);
    for (int i = 0; i < n; ++i) {
        double d1, d2;
        cin >> d1 >> d2;
        pos.push_back(make_pair(d1, d2));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            double dist = sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2));
            adj[i].push_back(make_pair(j, dist));
            adj[j].push_back(make_pair(i, dist));
        }
    }
    vector<pair<int, int>> sel;
    cout << fixed;
    cout.precision(2);
    cout << kruskal(sel) << '\n';

    return 0;
}