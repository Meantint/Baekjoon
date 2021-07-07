#include <iostream>
#include <queue>

#define PII pair<int, int>

using namespace std;

int n1, n2;

int main()
{
    cin >> n1 >> n2;

    int pos;
    int dist;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    vector<bool> isCheck(100010, false);

    q.push(make_pair(0, n1));
    while (!q.empty()) {
        pos = q.top().second;
        dist = q.top().first;

        q.pop();
        // 이미 방문했었다면
        if (isCheck[pos]) {
            continue;
        }
        // 동생 위치에 도달했다면
        if (pos == n2) {
            cout << dist << '\n';
            return 0;
        }

        if (pos - 1 >= 0) {
            q.push(make_pair(dist + 1, pos - 1));
        }
        if (pos + 1 <= 100000) {
            q.push(make_pair(dist + 1, pos + 1));
        }
        if (pos * 2 <= 100000) {
            q.push(make_pair(dist, pos * 2));
        }
        isCheck[pos] = true;
    }

    return 0;
}