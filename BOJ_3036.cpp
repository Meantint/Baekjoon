#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

int gcd(int n1, int n2)
{
    if (n1 < n2) swap(n1, n2);

    if (n1 % n2 == 0) return n2;
    return gcd(n2, n1 % n2);
}

int main()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i < n; ++i) {
        int gcdNum = gcd(v[0], v[i]);
        cout << v[0] / gcdNum << '/' << v[i] / gcdNum << '\n';
    }

    return 0;
}