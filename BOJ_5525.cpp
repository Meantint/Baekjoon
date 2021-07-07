#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, less<int>> pq;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num == 0) {
            if (pq.empty()) {
                cout << '0' << '\n';
                continue;
            }
            cout << pq.top() << '\n';
            pq.pop();
        }
        else {
            pq.push(num);
        }
    }

    return 0;
}