#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll a, b, c, d;

int main()
{
    cin >> a >> b >> c >> d;

    cout << stoll(to_string(a) + to_string(b)) + stoll(to_string(c) + to_string(d)) << '\n';

    return 0;
}