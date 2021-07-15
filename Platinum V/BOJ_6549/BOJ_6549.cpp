#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n;
ll answer;

ll DC(int low, int high, vector<ll>& h)
{
    ll ret = 0;

    ll left_max, right_max;
    int mid = (low + high) / 2;
    if (low != high) {
        left_max = DC(low, mid, h);
        right_max = DC(mid + 1, high, h);
        ret = (left_max < right_max ? right_max : left_max);

        ll mid_to_left = mid;
        ll mid_to_right = mid + 1;

        ll h_min = (h[mid + 1] < h[mid] ? h[mid + 1] : h[mid]);
        while (mid_to_left != low || mid_to_right != high) {
            ll temp = (mid_to_right - mid_to_left + (ll)1) * h_min;
            if (ret < temp) {
                ret = temp;
            }

            if (mid_to_left == low) {
                ++mid_to_right;
                if (h_min > h[mid_to_right]) {
                    h_min = h[mid_to_right];
                }
            }
            else if (mid_to_right == high) {
                --mid_to_left;
                if (h_min > h[mid_to_left]) {
                    h_min = h[mid_to_left];
                }
            }
            else {
                if (h[mid_to_left - 1] >= h[mid_to_right + 1]) {
                    --mid_to_left;
                    if (h_min > h[mid_to_left]) {
                        h_min = h[mid_to_left];
                    }
                }
                else {
                    ++mid_to_right;
                    if (h_min > h[mid_to_right]) {
                        h_min = h[mid_to_right];
                    }
                }
            }
        }
        ll temp = (mid_to_right - mid_to_left + (ll)1) * h_min;

        return (ret < temp ? temp : ret);
    }
    else {
        return h[low];
    }
}

void solve(vector<ll>& h)
{
    answer = 0;

    int low = 0, high = h.size() - 1;
    answer = DC(low, high, h);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<ll> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        solve(h);

        cout << answer << '\n';
    }

    return 0;
}