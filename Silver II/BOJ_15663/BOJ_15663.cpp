#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> info, comb;
vector<vector<int>> answer;

void DFS(int idx, vector<int> curInfo)
{
    curInfo.push_back(idx);
    if (curInfo.size() == m) {
        answer.push_back(curInfo);
        return;
    }

    int cSize = curInfo.size();
    for (int i = 0; i < n; ++i) {
        bool putThis = true;
        for (int j = 0; j < cSize; ++j) {
            if (i == curInfo[j]) {
                putThis = false;
                break;
            }
        }
        if (putThis) {
            DFS(i, curInfo);
        }
    }

    return;
}

int main()
{
    cin >> n >> m;
    info.resize(n);
    comb.resize(n, 1);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }
    sort(info.begin(), info.end());
    for (int i = 0; i < m; ++i) {
        comb[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        DFS(i, {});
    }
    int aSize = answer.size();
    for (int i = 0; i < aSize; ++i) {
        for (int j = 0; j < m; ++j) {
            answer[i][j] = info[answer[i][j]];
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    aSize = answer.size();
    for (int i = 0; i < aSize; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}