#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> nH(n);
    vector<string> nS(m);
    for (int i = 0; i < n; ++i) {
        cin >> nH[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> nS[i];
    }
    sort(nH.begin(), nH.end());
    sort(nS.begin(), nS.end());
    vector<string> ans;
    int idx1 = 0;
    int idx2 = 0;
    while (idx1 < nH.size() && idx2 < nS.size()) {
        if (nH[idx1] == nS[idx2]) {
            ans.push_back(nH[idx1]);
            ++idx1;
            ++idx2;
        }
        else if (nH[idx1] < nS[idx2]) {
            ++idx1;
        }
        else {
            ++idx2;
        }
    }
    int aSize = ans.size();
    cout << aSize << '\n';
    for (int i = 0; i < aSize; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}