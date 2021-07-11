#include <algorithm>
#include <iostream>
#include <vector>

#define PII pair<int, int>
#define ll long long

using namespace std;

int n, s;

int main()
{
    cin >> n >> s;
    vector<ll> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    int st = 0;
    int ed = 1;
    int minLen = 2112345678;
    ll sum = num[st] + num[ed];
    while (ed < n) {
        if (sum >= s) {
            if (ed - st + 1 < minLen) {
                minLen = ed - st + 1;
            }
            if (st == ed) {
                ++st;
                ++ed;
                sum = sum + num[ed] - num[ed - 1];
            }
            else {
                sum -= num[st];
                ++st;
            }
        }
        else {
            ++ed;
            sum += num[ed];
        }
    }
    if (minLen == 2112345678) {
        cout << '0' << '\n';
    }
    else {
        cout << minLen << '\n';
    }

    return 0;
}