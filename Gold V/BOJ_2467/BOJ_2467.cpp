#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> info;

int main()
{
    cin >> n;
    info.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
        // cout << info[i] << '\n';
    }

    int size = info.size();
    int lo = 0, hi = size - 1;
    int now = info[lo] + info[hi];
    int updateAns = 2112345678;
    pair<int, int> answer = make_pair(-1, -1);
    while (0 <= hi && lo < size && lo < hi) {
        if (abs(updateAns) > abs(now)) {
            updateAns = now;
            answer = make_pair(info[lo], info[hi]);
        }

        // 사이에 최소 하나 이상 존재한다면
        if (hi - lo > 1) {
            int changeLow = now - info[lo] + info[lo + 1];
            int changeHigh = now - info[hi] + info[hi - 1];

            if (abs(changeLow) < abs(changeHigh)) {
                now = changeLow;
                ++lo;
            }
            else {
                now = changeHigh;
                --hi;
            }
        }
        else {
            break;
        }
    }
    cout << answer.first << ' ' << answer.second << '\n';

    return 0;
}