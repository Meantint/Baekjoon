#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;

struct comp {
    bool operator()(int i1, int i2)
    {
        if (abs(i1) == abs(i2)) {
            return i1 > i2;
        }
        return abs(i1) > abs(i2);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    priority_queue<int, vector<int>, comp> pq;
    while (n--) {
        int num;
        cin >> num;

        if (num != 0) {
            pq.push(num);
        }
        else {
            if (pq.empty()) {
                cout << '0' << '\n';

                continue;
            }
            cout << pq.top() << '\n';
            pq.pop();
        }
    }

    return 0;
}