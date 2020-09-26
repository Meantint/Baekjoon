#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << '0' << '\n';

                continue;
            }
            cout << pq.top() << '\n';
            pq.pop();
        }
        else {
            pq.push(x);
        }
    }
}