#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n, m;
int mapIdx = 0;
string king;
vector<int> ind;
vector<long long> cost;
vector<vector<int>> adj;

int main()
{
    cin >> n >> m >> king;
    map<string, int> strIdx;
    for (int i = 0; i < n; ++i) {
        string child, p1, p2;
        cin >> child >> p1 >> p2;

        if (strIdx.count(child) == 0) {
            strIdx[child] = mapIdx;
            // size 1 증가 시켜준다.
            ind.push_back(0);
            adj.push_back({});
            ++mapIdx;
        }
        if (strIdx.count(p1) == 0) {
            strIdx[p1] = mapIdx;
            // size 1 증가 시켜준다.
            ind.push_back(0);
            adj.push_back({});
            ++mapIdx;
        }
        if (strIdx.count(p2) == 0) {
            strIdx[p2] = mapIdx;
            // size 1 증가 시켜준다.
            ind.push_back(0);
            adj.push_back({});
            ++mapIdx;
        }
        ind[strIdx[child]] += 2;
        adj[strIdx[p1]].push_back(strIdx[child]);
        adj[strIdx[p2]].push_back(strIdx[child]);
    }
    // for (int i = 0; i < adj.size(); ++i) {
    //     for (int j = 0; j < adj[i].size(); ++j) {
    //         cout << adj[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cost.resize(ind.size(), 0);
    cost[strIdx[king]] = pow(2, 60);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < adj[cur].size(); ++i) {
            int next = adj[cur][i];

            cost[next] += (cost[cur] / 2);
            --ind[next];
            if (ind[next] == 0) {
                q.push(next);
            }
        }
    }
    string answer = "";
    for (int i = 0; i < m; ++i) {
        string str;
        cin >> str;
        if (answer == "") {
            answer = str;
        }

        if (cost[strIdx[answer]] < cost[strIdx[str]]) {
            answer = str;
        }
    }
    cout << answer << '\n';
    // cout << cost[strIdx[answer]] << '\n';

    return 0;
}