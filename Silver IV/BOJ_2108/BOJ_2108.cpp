#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n;
vector<int> info;
map<int, int> m;
vector<int> answer(4);

bool comp(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

int main()
{
    int sum = 0;
    cin >> n;
    info.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];

        // 각 값들의 개수 저장을 위한 map<int, int>
        if (m.find(info[i]) == m.end()) {
            m[info[i]] = 1;
        }
        else {
            ++m[info[i]];
        }
        // 산술평균을 위한 sum
        sum += info[i];
    }
    sort(info.begin(), info.end());

    answer[0] = floor(sum / (double)n + 0.5);
    answer[1] = info[n / 2];
    vector<pair<int, int>> fq(m.begin(), m.end());
    sort(fq.begin(), fq.end(), comp);
    if (fq.size() > 1 && fq[0].second == fq[1].second) {
        answer[2] = fq[1].first;
    }
    else {
        answer[2] = fq[0].first;
    }
    answer[3] = info.back() - info[0];

    for (auto ans : answer) {
        cout << ans << '\n';
    }

    return 0;
}