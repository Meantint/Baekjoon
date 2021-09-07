#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, k;
vector<bool> isKnown;
vector<vector<int>> party, people;  // 파티 기준 링크, 사람 기준 링크
vector<bool> answer;

void BFS()
{
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (isKnown[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int curPeople = q.front();
        q.pop();

        // cout << "curPeople : " << curPeople << '\n';

        int size = people[curPeople].size();
        for (int i = 0; i < size; ++i) {  // 이 사람이 간 파티 모두 찾기
            int curParty = people[curPeople][i];
            // cout << "curParty : " << curParty << '\n';
            if (answer[curParty]) {
                answer[curParty] = false;
                int pSize = party[curParty].size();
                for (int j = 0; j < pSize; ++j) {
                    int nextPeople = party[curParty][j];
                    if (!isKnown[nextPeople]) {
                        isKnown[nextPeople] = true;
                        q.push(nextPeople);
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    isKnown.resize(n + 1, false);
    people.resize(n + 1);
    party.resize(m);
    answer.resize(m, true);
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int p;
        cin >> p;
        isKnown[p] = true;
    }
    for (int i = 0; i < m; ++i) {
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int p;
            cin >> p;
            party[i].push_back(p);
            people[p].push_back(i);
        }
    }

    BFS();

    int ret = 0;
    for (int i = 0; i < m; ++i) {
        //     cout << "answer[" << i << "] : " << answer[i] << '\n';
        if (answer[i]) {
            ++ret;
        }
    }
    cout << ret << '\n';

    return 0;
}