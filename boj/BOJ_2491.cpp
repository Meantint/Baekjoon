#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dpMax;
vector<int> dpMin;
vector<int> cost;

int main()
{
    cin >> n;
    cost.resize(n);
    dpMax.resize(n);
    dpMin.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    dpMax[0] = dpMin[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (cost[i - 1] <= cost[i]) {
            dpMax[i] = dpMax[i - 1] + 1;
        }
        else {
            dpMax[i] = 1;
        }
        if (cost[i - 1] >= cost[i]) {
            dpMin[i] = dpMin[i - 1] + 1;
        }
        else {
            dpMin[i] = 1;
        }
    }
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        answer = max({dpMax[i], dpMin[i], answer});
    }
    cout << answer << '\n';

    return 0;
}