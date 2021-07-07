#include <iostream>
#include <queue>

#define PII pair<int, int>

using namespace std;

int x, answer = -1;
queue<PII> q;

int main()
{
    cin >> x;

    vector<bool> isVisited(x + 1, false);
    q.push(make_pair(x, 0));
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // 이미 방문한적이 있다면
        if (isVisited[cur]) {
            continue;
        }
        isVisited[cur] = true;

        if (cur == 1) {
            answer = cnt;
            break;
        }
        if (cur % 3 == 0) {
            q.push(make_pair(cur / 3, cnt + 1));
        }
        if (cur % 2 == 0) {
            q.push(make_pair(cur / 2, cnt + 1));
        }
        q.push(make_pair(cur - 1, cnt + 1));
    }
    cout << answer << '\n';

    return 0;
}