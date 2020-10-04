// 투 포인터 문제

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, st = 0, ed = 1;
PII answer;
vector<int> v;

int main()
{
    cin >> n;
    v = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int val = 2112345678;
    st = 0;
    ed = n - 1;
    while (st != ed) {
        if (abs(val) > abs(v[st] + v[ed])) {
            answer.first = st;
            answer.second = ed;
            val = v[st] + v[ed];
        }

        if (v[st] + v[ed] > 0) {
            --ed;
        }
        else if (v[st] + v[ed] < 0) {
            ++st;
        }
        else {
            break;
        }
    }
    cout << v[answer.first] << ' ' << v[answer.second] << '\n';

    return 0;
}