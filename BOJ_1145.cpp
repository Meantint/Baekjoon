#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v(5);

int gcd(int n1, int n2)
{
    if (n1 < n2) swap(n1, n2);

    if (n1 % n2 == 0) return n2;
    return gcd(n2, n1 % n2);
}

int main()
{
    for (int i = 0; i < 5; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int answer = 2112345678;
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                int g1 = v[i] * v[j] / gcd(v[i], v[j]);
                // cout << gcd(v[i], v[j]) << '\n';
                int g2 = g1 * v[k] / gcd(g1, v[k]);
                answer = min(answer, g2);
            }
        }
    }
    cout << answer << '\n';

    return 0;
}