#include <iostream>
#include <vector>

using namespace std;

int n, k;
int answer = 0;
vector<int> cost;

int main()
{
    cin >> n >> k;
    cost.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    int costIdx = cost.size() - 1;
    while (k != 0) {
        if (cost[costIdx] <= k) {
            answer += (k / cost[costIdx]);
            k %= cost[costIdx];
        }
        else {
            --costIdx;
        }
    }
    cout << answer << '\n';

    return 0;
}