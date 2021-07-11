#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

void printDfs(int start, vector<int> forPrint)
{
    if (forPrint.size() == m - 1) {
        for (int i = 0; i < m - 1; ++i) {
            cout << v[forPrint[i]] << ' ';
        }
        cout << v[start] << '\n';

        return;
    }
    forPrint.push_back(start);
    for (int i = start; i < n; ++i) {
        printDfs(i, forPrint);
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
    for (int i = 0; i < n; ++i) {
        printDfs(i, {});
    }

    return 0;
}