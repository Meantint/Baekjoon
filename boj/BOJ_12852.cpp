// 방문했는지의 여부를 bool 형태가 아닌
// parent[idx] = idx인지의 여부로 참거짓을 판별해준다.
// 그 후 path를 parent를 거꾸로 읽으면서 받아와서 출력하면 됨

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n;
vector<int> parent;

int main()
{
    cin >> n;
    parent = vector<int>(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        parent[i] = i;
    }

    queue<PII> q;
    q.push(make_pair(0, n));

    while (!q.empty()) {
        int dist = q.front().first;
        int val = q.front().second;
        q.pop();

        if (val == 1) {
            vector<int> path;
            while (parent[val] != val) {
                path.push_back(val);
                val = parent[val];
            }
            path.push_back(val);
            reverse(path.begin(), path.end());
            cout << path.size() - 1 << '\n';
            for (int i = 0; i < path.size(); ++i) {
                cout << path[i] << ' ';
            }
            cout << '\n';
            break;
        }
        if (val % 3 == 0 && parent[val / 3] == val / 3) {
            parent[val / 3] = val;
            q.push(make_pair(dist + 1, val / 3));
        }
        if (val % 2 == 0 && parent[val / 2] == val / 2) {
            parent[val / 2] = val;
            q.push(make_pair(dist + 1, val / 2));
        }
        if (val - 1 > 0 && parent[val - 1] == val - 1) {
            parent[val - 1] = val;
            q.push(make_pair(dist + 1, val - 1));
        }
    }

    return 0;
}