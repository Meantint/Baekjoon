#include <cmath>
#include <iostream>

using namespace std;

long long solve(long long a, long long b, long long c)
{
    if (b == 1) {
        return a % c;
    }
    if (b == 2) {
        return (a * a) % c;
    }
    // 짝수라면
    if (b % 2 == 0) {
        return (solve(a, b / 2, c) * solve(a, b / 2, c)) % c;
    }
    // 홀수라면
    else {
        return (solve(a, b - 1, c) * a) % c;
    }
}

int main()
{
    long long a, b, c;

    cin >> a >> b >> c;
    cout << solve(a, b, c) << '\n';

    return 0;
}