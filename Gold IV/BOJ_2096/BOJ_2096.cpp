#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> cost(3);
vector<int> dpMin(3), dpMax(3);

int main()
{
    cin >> n;
    for (int j = 0; j < 3; ++j) {
        cin >> cost[j];
    }
    dpMin = dpMax = cost;
    for (int i = 1; i < n; ++i) {
        cin >> cost[0] >> cost[1] >> cost[2];
        vector<int> temp = dpMin;
        dpMin[0] = min(temp[0], temp[1]) + cost[0];
        dpMin[1] = *min_element(temp.begin(), temp.end()) + cost[1];
        dpMin[2] = min(temp[1], temp[2]) + cost[2];

        temp = dpMax;
        dpMax[0] = max(temp[0], temp[1]) + cost[0];
        dpMax[1] = *max_element(temp.begin(), temp.end()) + cost[1];
        dpMax[2] = max(temp[1], temp[2]) + cost[2];
    }
    cout << *max_element(dpMax.begin(), dpMax.end()) << ' ' << *min_element(dpMin.begin(), dpMin.end()) << '\n';

    return 0;
}