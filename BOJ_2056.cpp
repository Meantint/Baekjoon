// 위상 정렬에서의 indegree 값을 bool이 아닌 int 값으로
// 개수를 저장해둬야 효율적 계산이 가능함.
// queue로 cur를 방문할 때마다 --indegree[cur]를 실행해주고 indegree[cur] == 0일때!! 들어오는
// 모든 경로에서의 최대값 연산을 완료했기 때문에 q.push(cur)를 실행해준다.

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, m, cost;
vector<vector<int>> adj;
vector<int> nodeCost;
vector<int> accCost;
vector<int> indegree;

int main()
{
    cin >> n;
    adj.resize(n);
    nodeCost.resize(n);
    accCost.resize(n);
    indegree.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nodeCost[i] >> m;
        accCost[i] = nodeCost[i];
        for (int j = 0; j < m; ++j) {
            int st;
            cin >> st;

            adj[st - 1].push_back(i);
            ++indegree[i];
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    int answer = 0;
    while (!q.empty()) {
        int curNode = q.front();
        q.pop();

        // cout << accCost[curNode] << ", " << curNode << '\n';
        int nodeSize = adj[curNode].size();
        for (int i = 0; i < nodeSize; ++i) {
            int next = adj[curNode][i];
            if (accCost[next] < nodeCost[next] + accCost[curNode]) {
                accCost[next] = nodeCost[next] + accCost[curNode];
            }

            --indegree[next];
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    for (int i = 0; i < accCost.size(); ++i) {
        answer = max(answer, accCost[i]);
    }
    cout << answer << '\n';

    return 0;
}