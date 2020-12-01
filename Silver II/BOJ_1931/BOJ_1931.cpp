#include <algorithm>
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, answer = 1;
vector<PII> v;

bool comp(const PII& p1, const PII& p2)
{
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    PII prev;
    sort(v.begin(), v.end(), comp);
    for (auto& p : v) {
        if (p.first <= p.second) {
            prev = p;
            break;
        }
    }
    for (int i = 1; i < n; ++i) {
        // 말이 안되는 경우
        if (v[i].first > v[i].second) {
            continue;
        }
        // 이전 회의실 이용 시간이 지났다면 사용 가능
        if (v[i].first >= prev.second) {
            prev = v[i];
            ++answer;
        }
    }
    cout << answer << '\n';

    return 0;
}