#include <bits/stdc++.h>

using namespace std;

int main()
{
        int k, n;
        cin >> k >> n;

        long long maxVal = 0;
        vector<long long> val(k, 0);
        for (int i = 0; i < k; ++i) {
                cin >> val[i];
                if (maxVal < val[i])
                        maxVal = val[i];
        }

        long long start = 1;
        long long end = maxVal;
        long long mid;
        long long max = 0;
        while (start <= end) {
                mid = (start + end) / 2;
                long long sum = 0;
                for (int i = 0; i < k; ++i) {
                        sum += (val[i] / mid);
                }
                if (sum >= n) {
                        start = mid + 1;
                        if (mid > max) {
                                max = mid;
                        }
                }
                else
                        end = mid - 1;
        }
        cout << max << '\n';

        return 0;
}