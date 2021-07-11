#include <bits/stdc++.h>

using namespace std;

long long n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<int> tree(n);
    for (int i = 0; i < n; ++i) {
        cin >> tree[i];
    }

    int start = 0, end = 2000000000;
    int mid;

    int answer = -1;
    long long sum;
    while (start <= end) {
        mid = (start + end) / 2;
        sum = 0;
        for (int i = 0; i < n; ++i) {
            if (tree[i] > mid) {
                sum += (tree[i] - mid);
            }
        }
        if (sum >= m) {
            answer = max(answer, mid);
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    cout << answer << '\n';

    return 0;
}