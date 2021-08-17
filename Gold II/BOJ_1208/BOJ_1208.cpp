#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll n, s;
ll ret = 0;
int r1, r2;
vector<ll> arr, arr1, arr2;

void dfs1(int cur, ll value, int inputCount)
{
    if (cur == r1) {
        if (inputCount != 0) {
            arr1.push_back(value);
        }
        return;
    }

    dfs1(cur + 1, value, inputCount);
    dfs1(cur + 1, value + arr[cur], inputCount + 1);
}

void dfs2(int cur, ll value, int inputCount)
{
    if (cur == n) {
        if (inputCount != 0) {
            arr2.push_back(value);
        }
        return;
    }

    dfs2(cur + 1, value, inputCount);
    dfs2(cur + 1, value + arr[cur], inputCount + 1);
}

int main()
{
    cin >> n >> s;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // n = 1인 경우
    if (n == 1) {
        if (arr[0] == s) {
            cout << 1 << '\n';
            return 0;
        }
        else {
            cout << 0 << '\n';
            return 0;
        }
    }

    r1 = n - n / 2;

    dfs1(0, 0, 0);
    sort(arr1.begin(), arr1.end());
    dfs2(r1, 0, 0);

    for (int i = 0; i < arr1.size(); ++i) {
        if (arr1[i] == s) {
            ++ret;
        }
    }
    for (int i = 0; i < arr2.size(); ++i) {
        if (arr2[i] == s) {
            ++ret;
        }
        ret += (ll)(upper_bound(arr1.begin(), arr1.end(), s - arr2[i]) - lower_bound(arr1.begin(), arr1.end(), s - arr2[i]));
    }

    cout << ret << '\n';

    return 0;
}