#include <iostream>
#include <string>

#define ll long long

using namespace std;

string str1, str2;

int main()
{
    cin >> str1 >> str2;

    ll answer = 0;

    for (auto ch1 : str1) {
        for (auto ch2 : str2) {
            answer += (ll)((ch1 - '0') * (ch2 - '0'));
        }
    }
    cout << answer << '\n';

    return 0;
}