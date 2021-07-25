#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n;
string str;
map<string, int> m;

bool comp(pair<string, int>& p1, pair<string, int>& p2)
{
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

int main()
{
    cin >> n;
    while (n--) {
        cin >> str;

        if (m.find(str) == m.end()) {
            m[str] = 1;
        }
        else {
            ++m[str];
        }
    }

    vector<pair<string, int>> answer(m.begin(), m.end());
    sort(answer.begin(), answer.end(), comp);

    cout << answer[0].first << '\n';

    return 0;
}