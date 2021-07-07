#include <iostream>
#include <queue>

#define ll long long
#define PLL pair<ll, ll>

using namespace std;

ll a, b;

int main()
{
    cin >> a >> b;

    queue<PLL> q;
    q.push(make_pair(1, a));
    while (!q.empty()) {
        ll dist = q.front().first;
        ll val = q.front().second;
        q.pop();

        if (val == b) {
            cout << dist << '\n';

            return 0;
        }
        else if (val > b) {
            continue;
        }

        q.push(make_pair(dist + 1, val * 2));
        q.push(make_pair(dist + 1, val * 10 + 1));
    }
    cout << "-1" << '\n';

    return 0;
}