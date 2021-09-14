#include <iostream>
#include <queue>
#include <vector>

#define ll long long

using namespace std;

ll a, b;

int BFS()
{
    int ret = -1;

    queue<pair<ll, ll>> q;
    q.push(make_pair(a, 1));
    while (!q.empty()) {
        ll cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (cur > b) {
            continue;
        }
        if (cur == b) {
            ret = dist;
            break;
        }

        q.push(make_pair(cur * 2, dist + 1));
        q.push(make_pair(cur * 10 + 1LL, dist + 1));
    }

    return ret;
}

int main()
{
    cin >> a >> b;

    cout << BFS() << '\n';

    return 0;
}