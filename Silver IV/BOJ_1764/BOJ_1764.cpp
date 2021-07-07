#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n, m, idx = 0;
string name = "";
vector<string> answer;
map<string, int> dbj;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (n--) {
        cin >> name;
        dbj[name] = idx;
        ++idx;
    }
    while (m--) {
        cin >> name;
        // 보도 못한 사람 중에 듣지도 못한 사람이 있을 때
        if (dbj.find(name) != dbj.end()) {
            answer.push_back(name);
        }
    }
    // 사전순으로 정렬한다.
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (auto& ans : answer) {
        cout << ans << '\n';
    }

    return 0;
}