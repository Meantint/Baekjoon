#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n;
ll m;
vector<ll> info;

int BS(int low, int high)
{
    int ret = 0;
    int size = info.size();
    int mid;

    while (low <= high) {
        ll sum = 0;

        mid = (low + high) >> 1;
        for (int i = 0; i < size; ++i) {
            if (info[i] - mid < 0) {
                continue;
            }
            sum += (info[i] - mid);
        }

        if (m <= sum) {
            if (ret < mid) {
                ret = mid;
                // cout << "wow, " << low << ", " << high << '\n';
                // cout << "new ret : " << ret << '\n';
            }
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ret;
}

int main()
{
    cin >> n >> m;
    info.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }

    cout << BS(1, *max_element(info.begin(), info.end())) << '\n';

    return 0;
}