#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string s1, s2;

int main()
{
    cin >> s1 >> s2;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    cout << (s1 > s2 ? s1 : s2) << '\n';

    return 0;
}