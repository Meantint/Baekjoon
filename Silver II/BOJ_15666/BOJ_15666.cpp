#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int iSize;
vector<int> info;

void DFS(int idx, vector<int> curInfo)
{
    curInfo.push_back(info[idx]);
    if (curInfo.size() == m) {
        for (int i = 0; i < m; ++i) {
            cout << curInfo[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = idx; i < iSize; ++i) {
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
    info.erase(unique(info.begin(), info.end()), info.end());

    iSize = info.size();
    for (int i = 0; i < iSize; ++i) {
        DFS(i, {});
    }

    return 0;
}