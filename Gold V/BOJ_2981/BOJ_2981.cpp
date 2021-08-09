#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int gcd(int x, int y)
{
    if (x % y == 0) {
        return y;
    }
    return gcd(y, x % y);
}

int solve()
{
    sort(arr.begin(), arr.end());

    vector<int> sub;
    for (int i = 1; i < n; ++i) {
        sub.push_back(arr[i] - arr[i - 1]);
    }

    int ret = sub[0];
    int subSize = sub.size();
    for (int i = 1; i < subSize; ++i) {
        ret = gcd(ret, sub[i]);
    }

    return ret;
}

int main()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int ret = solve();
    vector<int> answer;

    for (int i = 1; i * i <= ret; ++i) {
        if (ret % i == 0) {
            answer.push_back(i);
            if (i * i == ret) {
                continue;
            }
            answer.push_back(ret / i);
        }
    }
    sort(answer.begin(), answer.end());
    for (int i = 1; i < answer.size(); ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}