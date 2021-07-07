#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int x, cost1, cost5, cost10, cost25;
int maxCost;
vector<bool> dp;
bool isDone = false;

int main()
{
    cin >> x >> cost1 >> cost5 >> cost10 >> cost25;
    maxCost = cost1 + 5 * cost5 + 10 * cost10 + 25 * cost25;
    dp.resize(maxCost + 1, 0);

    queue<tuple<int, int, int, int, int>> q;
    q.push(make_tuple(maxCost, cost1, cost5, cost10, cost25));
    while (!q.empty()) {
        int cost = get<0>(q.front());
        int c1 = get<1>(q.front());
        int c5 = get<2>(q.front());
        int c10 = get<3>(q.front());
        int c25 = get<4>(q.front());
        q.pop();

        if (cost == x) {
            cout << c1 << ' ' << c5 << ' ' << c10 << ' ' << c25 << '\n';
            isDone = true;

            break;
        }
        if (dp[cost]) continue;
        dp[cost] = true;
        if (c25 != 0) {
            q.push(make_tuple(cost - 25, c1, c5, c10, c25 - 1));
        }
        if (c10 != 0) {
            q.push(make_tuple(cost - 10, c1, c5, c10 - 1, c25));
        }
        if (c5 != 0) {
            q.push(make_tuple(cost - 5, c1, c5 - 1, c10, c25));
        }
        if (c1 != 0) {
            q.push(make_tuple(cost - 1, c1 - 1, c5, c10, c25));
        }
    }
    if (!isDone) {
        cout << "0 0 0 0\n";
    }

    return 0;
}