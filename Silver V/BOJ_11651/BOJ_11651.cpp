#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> info;

bool comp(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main()
{
    cin >> n;
    info.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i].first >> info[i].second;
    }
    sort(info.begin(), info.end(), comp);

    for (int i = 0; i < n; ++i) {
        cout << info[i].first << ' ' << info[i].second << '\n';
    }

    return 0;
}