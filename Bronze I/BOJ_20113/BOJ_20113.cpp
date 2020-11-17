#include <algorithm>
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, k;

int main()
{
    cin >> n;
    // (투표 받은 개수, 플레이어 번호)
    vector<PII> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(make_pair(0, i + 1));
    }
    while (n--) {
        cin >> k;
        // 투표를 건너 뛴다면 continue
        if (k == 0) {
            continue;
        }
        ++v[k - 1].first;
    }
    sort(v.begin(), v.end(), greater<PII>());

    // 공동 1위라면
    if (v[0].first == v[1].first) {
        cout << "skipped" << '\n';
    }
    // 혼자 1위라면
    else {
        cout << v[0].second << '\n';
    }

    return 0;
}