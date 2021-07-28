#include <iostream>
#include <vector>

using namespace std;

int tc;
int n, answer;
vector<int> edge;
vector<bool> isVisited;

void dfs(int index)
{
    if (isVisited[index]) {
        return;
    }
    isVisited[index] = true;
    dfs(edge[index]);
}

void solve()
{
    answer = 0;
    isVisited.resize(edge.size(), false);

    for (int i = 1; i <= n; ++i) {
        if (isVisited[i]) {
            continue;
        }
        ++answer;
        dfs(i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        // init
        edge.clear();
        isVisited.clear();

        cin >> n;

        edge.resize(n + 1, -1);
        for (int i = 1; i <= n; ++i) {
            cin >> edge[i];
        }

        solve();

        cout << answer << '\n';
    }

    return 0;
}