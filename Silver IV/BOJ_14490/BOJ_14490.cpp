#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

using namespace std;

string str;

int gcd(int a, int b)
{
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main()
{
    cin >> str;

    int target = str.find(":");
    int n1 = stoi(str.substr(0, target));
    int n2 = stoi(str.substr(target + 1));

    int c = gcd(n1, n2);
    cout << to_string(n1 / c) + ":" + to_string(n2 / c) << '\n';

    return 0;
}