#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
// vector<int> pv;

void printDfs(int cur, vector<int> forPrint)
{
    if (forPrint.size() == m - 1) {
        // if (pv == forPrint) {
        //     return;
        // }
        int fpSize = forPrint.size();
        for (int i = 0; i < fpSize; ++i) {
            cout << forPrint[i] << ' ';
        }
        cout << v[cur] << '\n';

        return;
    }
    forPrint.push_back(v[cur]);
    int prevNum = -1;
    for (int next = cur; next < n; ++next) {
        if (prevNum == v[next]) continue;
        printDfs(next, forPrint);
        prevNum = v[next];
    }
}

int main()
{
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int prevNum = -1;
    for (int i = 0; i < n; ++i) {
        if (prevNum == v[i]) continue;
        // pv.resize(m, -1);
        printDfs(i, {});
        prevNum = v[i];
    }

    return 0;
}