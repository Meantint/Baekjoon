#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n;
int idx = 0;
map<int, int> m;
vector<int> v, c;

int main()
{
    cin >> n;
    v.resize(n), c.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    c = v;
    sort(c.begin(), c.end());

    for (auto& elem : c) {
        // 똑같은 원소가 없을 때만 실행
        if (m.find(elem) == m.end()) {
            m[elem] = idx;
            ++idx;
        }
    }
    for (auto& elem : v) {
        cout << m[elem] << ' ';
    }
    cout << '\n';

    return 0;
}