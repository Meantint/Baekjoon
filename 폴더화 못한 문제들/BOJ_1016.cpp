#include <bits/stdc++.h>

using namespace std;

bool isPrime[1000001] = { 0 };
long long num[1000001] = { 0 };

int main()
{
    long long min_num, max_num;
    cin >> min_num >> max_num;

    for (long long i = 2; i * i <= max_num; ++i) {
        long long start = min_num / (i * i);
        if (start * i * i != min_num) {
            ++start;
        }
        for (long long j = start; i * i * j <= max_num; ++j) {
            isPrime[i * i * j - min_num] = true;
        }
    }
    int answer = 0;
    for (long long i = 0; i < max_num - min_num + (long long)1; ++i) {
        if (!isPrime[i]) {
            ++answer;
        }
    }
    cout << answer << '\n';

    return 0;
}