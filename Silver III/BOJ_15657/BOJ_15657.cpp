#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> info;

void DFS(int idx, vector<int> curInfo)
{
    if (idx == n) {
        return;
    }
    curInfo.push_back(info[idx]);
    if (curInfo.size() == m) {
        for (int i = 0; i < m; ++i) {
            cout << curInfo[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i < n; ++i) {
        DFS(i, curInfo);
    }
}

int main()
{
    cin >> n >> m;
    info.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }

    sort(info.begin(), info.end());
    for (int i = 0; i < n; ++i) {
        DFS(i, {});
    }

    return 0;
}