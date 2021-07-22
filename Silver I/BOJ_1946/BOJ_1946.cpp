#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int tc, n;

int main()
{
    cin >> tc;
    while (tc--) {
        int ret = 1;  // 0번째는 무조건 정답에 포함
        cin >> n;

        vector<pair<int, int>> rank(n);
        for (int i = 0; i < n; ++i) {
            cin >> rank[i].first >> rank[i].second;
        }
        sort(rank.begin(), rank.end());

        int high_rank = rank[0].second;
        for (int i = 1; i < n; ++i) {
            if (high_rank > rank[i].second) {
                high_rank = rank[i].second;
                ++ret;
            }
        }

        cout << ret << '\n';
    }

    return 0;
}