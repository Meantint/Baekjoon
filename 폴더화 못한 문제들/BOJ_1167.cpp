// dfs 2번 돌려야 함.
// 첫번째 : 루트에서 제일 먼 점.
// 두번째 : 첫번째에서 찾은 점에서 제일 먼 점(이게 지름)

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

#define PII pair<int, int>

using namespace std;

int v;

vector<vector<PII>> adj;
vector<bool> isVisited;

PII dfs(int cur)
{
    isVisited[cur] = true;

    PII maxDst = make_pair(0, cur);
    for (int there = 0; there < adj[cur].size(); ++there) {
        int next = adj[cur][there].first;
        int nextDst = adj[cur][there].second;
        // 이미 방문했었다면
        if (isVisited[next]) continue;
        PII tmp = dfs(next);
        if (maxDst.first < tmp.first + nextDst) {
            maxDst.first = tmp.first + nextDst;
            maxDst.second = tmp.second;
        }
    }

    return maxDst;
}

int main()
{
    cin >> v;
    adj.resize(v + 1);
    isVisited.resize(v + 1, false);
    for (int i = 0; i < v; ++i) {
        int v1;
        cin >> v1;

        while (1) {
            int v2, dist;
            cin >> v2;
            if (v2 == -1) break;
            cin >> dist;

            adj[v1].push_back(make_pair(v2, dist));
            // adj[v2].push_back(make_pair(v1, dist));
        }
    }
    int midVal = dfs(1).second;
    isVisited = vector<bool>(v + 1, false);
    int answer = dfs(midVal).first;
    cout << answer << '\n';

    return 0;
}