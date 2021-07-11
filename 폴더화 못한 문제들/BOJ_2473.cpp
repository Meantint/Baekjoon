#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int n;
tuple<int, int, int> answer;
vector<long long> v;

int main()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int st = 0;
    int ed = v.size() - 1;
    int mid = 1;
    long long savVal = 3000000000000;
    while (st != v.size() - 2) {
        bool isZero = false;
        while (mid != ed) {
            long long cur = v[st] + v[mid] + v[ed];
            if (abs(savVal) > abs(cur)) {
                savVal = cur;
                answer = make_tuple(st, mid, ed);
            }

            if (cur < 0) {
                ++mid;
            }
            else if (cur > 0) {
                --ed;
            }
            else {
                isZero = true;
                break;
            }
        }
        if (isZero) break;
        ++st;
        mid = st + 1;
        ed = v.size() - 1;
    }
    cout << v[get<0>(answer)] << ' ' << v[get<1>(answer)] << ' ' << v[get<2>(answer)] << '\n';

    return 0;
}