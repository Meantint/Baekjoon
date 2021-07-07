#include <bits/stdc++.h>

using namespace std;

int n;
long long r = 31;
long long m = 1234567891;

int main()
{
    cin >> n;

    string str;
    cin >> str;

    long long answer = 0;
    for (int i = 0; i < n; ++i) {
        long long num = str[i] - 'a' + 1;
        for (int j = 0; j < i; ++j) {
            num *= r;
            if (num >= m) {
                num %= m;
            }
        }
        answer += num;
        if (answer >= m) {
            answer %= m;
        }
    }

    cout << answer << '\n';

    return 0;
}