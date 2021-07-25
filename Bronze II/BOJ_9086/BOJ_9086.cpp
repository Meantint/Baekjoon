#include <iostream>
#include <string>

using namespace std;

int n;
string str;

int main()
{
    cin >> n;
    while (n--) {
        cin >> str;
        cout << str[0] << str.back() << '\n';
    }

    return 0;
}