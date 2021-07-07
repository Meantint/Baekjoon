#include <cmath>
#include <iostream>

using namespace std;

int k, n, m;

int main()
{
    cin >> k >> n >> m;

    double ans1, ans2;
    ans1 = pow(k, 2) / (pow(n, 2) + pow(m, 2)) * pow(n, 2);
    ans2 = pow(k, 2) / (pow(n, 2) + pow(m, 2)) * pow(m, 2);
    cout << (int)sqrt(ans1) << ' ' << (int)sqrt(ans2) << '\n';

    return 0;
}