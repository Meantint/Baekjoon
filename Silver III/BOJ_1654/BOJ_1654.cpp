#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n;
ll k;
vector<int> info;

int BS(ll low, ll high)
{
    int ret = 0;
    ll mid;
    int size = info.size();

    // cout << "low, high : " << low << ", " << high << '\n';

    while (low <= high) {
        mid = (low + high) >> 1;
        // cout << "mid : " << mid << '\n';

        ll temp = 0;
        for (int i = 0; i < size; ++i) {
            temp += (ll)(info[i] / mid);
        }

        if (k <= temp) {      // 현재 개수가 원하는 개수를 뛰어 넘었다면
            if (ret < mid) {  // 현재 길이가 더 크다면 갱신
                ret = mid;
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
    cin >> n >> k;
    info.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }

    cout << BS(1LL, *max_element(info.begin(), info.end())) << '\n';

    return 0;
}