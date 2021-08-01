#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int f, s, g, u, d;
vector<bool> isVisited;

int solve()
{
    queue<pair<int, int>> q;
    q.push(make_pair(s, 0));
    isVisited[s] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (cur == g) {
            return dist;
        }

        if (cur - d > 0 && !isVisited[cur - d]) {
            q.push(make_pair(cur - d, dist + 1));
            isVisited[cur - d] = true;
        }
        if (cur + u <= f && !isVisited[cur + u]) {
            q.push(make_pair(cur + u, dist + 1));
            isVisited[cur + u] = true;
        }
    }

    return -1;
}

int main()
{
    cin >> f >> s >> g >> u >> d;

    isVisited.resize(f + 1, false);

    int ret = solve();
    if (ret == -1) {
        cout << "use the stairs" << '\n';
    }
    else {
        cout << ret << '\n';
    }

    return 0;
}