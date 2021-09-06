#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cin >> n;
    while (n--) {
        int num;
        cin >> num;

        if (num != 0) {
            pq.push(make_pair(abs(num), num));
        }
        else {
            if (pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}