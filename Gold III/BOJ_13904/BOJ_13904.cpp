#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int dead_line;
vector<int> answer;
vector<pair<int, int>> info;

bool comp(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.second == p2.second) {
        return p1.first > p2.first;
    }
    return p1.second > p2.second;
}

void solve()
{
    sort(info.begin(), info.end(), comp);
    for (auto cur : info) {
        int idx = cur.first;
        while (0 < idx && answer[idx] != 0) {
            --idx;
        }
        if (idx != 0) {
            answer[idx] = cur.second;
        }
    }

    return;
}

int main()
{
    cin >> n;
    info.resize(n);

    dead_line = 0;
    for (int i = 0; i < n; ++i) {
        cin >> info[i].first >> info[i].second;
        if (dead_line < info[i].first) {
            dead_line = info[i].first;
        }
    }
    answer.resize(dead_line + 1, 0);

    solve();

    int real_answer = 0;
    for (auto ans : answer) {
        real_answer += ans;
    }
    cout << real_answer << '\n';

    return 0;
}