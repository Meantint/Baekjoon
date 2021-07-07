// isVisited를 들어가서 확인 하지 않고
// 들어가기전에 검사 후 true로 바꿔준 후 queue에 push한다.

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t, st, ed;

void bfs()
{
    queue<pair<int, string>> q;
    vector<bool> isVisited(10000, false);
    q.push(make_pair(st, ""));
    isVisited[st] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        string order = q.front().second;
        q.pop();

        if (cur == ed) {
            cout << order << '\n';

            break;
        }
        int tmp = (cur * 2) % 10000;
        if (!isVisited[tmp]) {
            isVisited[tmp] = true;
            q.push(make_pair(tmp, order + 'D'));
        }

        tmp = (cur + 9999) % 10000;
        if (!isVisited[tmp]) {
            isVisited[tmp] = true;
            q.push(make_pair(tmp, order + 'S'));
        }

        tmp = (cur % 1000) * 10 + cur / 1000;
        if (!isVisited[tmp]) {
            isVisited[tmp] = true;
            q.push(make_pair(tmp, order + 'L'));
        }

        tmp = cur / 10 + (cur % 10) * 1000;
        if (!isVisited[tmp]) {
            isVisited[tmp] = true;
            q.push(make_pair(tmp, order + 'R'));
        }
        isVisited[cur] = true;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> st >> ed;
        bfs();
    }

    return 0;
}