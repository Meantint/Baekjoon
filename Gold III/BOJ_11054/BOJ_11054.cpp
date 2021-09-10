#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> cost, dpAsc, dpDesc;
vector<int> lisA, lisD;

int main()
{
    cin >> n;
    cost.resize(n);
    dpAsc.resize(n);
    dpDesc.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    dpAsc[0] = 1;
    lisA.push_back(cost[0]);
    int lisAIdx = 1;
    for (int i = 1; i < n; ++i) {
        int targetIdx = 0;
        for (int j = lisAIdx - 1; j >= 0; --j) {
            if (lisA[j] < cost[i]) {
                targetIdx = j + 1;
                break;
            }
        }
        if (lisAIdx == targetIdx) {
            lisA.push_back(cost[i]);
            ++lisAIdx;
            dpAsc[i] = lisAIdx;
        }
        else {
            lisA[targetIdx] = cost[i];
            dpAsc[i] = targetIdx + 1;
        }
    }

    reverse(cost.begin(), cost.end());
    dpDesc[0] = 1;
    lisD.push_back(cost[0]);
    int lisDIdx = 1;
    for (int i = 1; i < n; ++i) {
        int targetIdx = 0;
        for (int j = lisDIdx - 1; j >= 0; --j) {
            if (lisD[j] < cost[i]) {
                targetIdx = j + 1;
                break;
            }
        }
        if (lisDIdx == targetIdx) {
            lisD.push_back(cost[i]);
            ++lisDIdx;
            dpDesc[i] = lisDIdx;
        }
        else {
            lisD[targetIdx] = cost[i];
            dpDesc[i] = targetIdx + 1;
        }
    }
    reverse(dpDesc.begin(), dpDesc.end());

    int ret = -1;
    for (int i = 0; i < n; ++i) {
        ret = max(ret, dpAsc[i] + dpDesc[i] - 1);
        // cout << "dpAsc, dpDesc : " << dpAsc[i] << ", " << dpDesc[i] << '\n';
    }
    cout << ret << '\n';

    return 0;
}