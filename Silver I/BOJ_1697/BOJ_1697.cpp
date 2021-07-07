#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, k, answer = -1;

int main()
{
    cin >> n >> k;

    vector<bool> isVisited(100010, false);
    queue<PII> q;
    q.push(make_pair(0, n));  // (이동 시간, 수빈이의 포지션)
    while (!q.empty()) {
        int dist = q.front().first;
        int cur = q.front().second;
        q.pop();

        // 이미 방문했다면
        if (isVisited[cur]) {
            continue;
        }
        isVisited[cur] = true;

        // 현재 위치가 동생의 위치라면
        if (cur == k) {
            answer = dist;
            break;
        }
        // queue 삽입
        if (cur - 1 >= 0) {
            q.push(make_pair(dist + 1, cur - 1));
        }
        if (cur + 1 <= 100000) {
            q.push(make_pair(dist + 1, cur + 1));
        }
        if (cur * 2 <= 100000) {
            q.push(make_pair(dist + 1, cur * 2));
        }
    }
    cout << answer << '\n';

    return 0;
}