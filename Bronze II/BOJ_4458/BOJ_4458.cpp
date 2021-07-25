#include <iostream>
#include <string>

using namespace std;

int n;
string str;

int main()
{
    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, str);
        if ('a' <= str[0] && str[0] <= 'z') {
            str[0] -= 32;
        }
        cout << str << '\n';
    }

    return 0;
}