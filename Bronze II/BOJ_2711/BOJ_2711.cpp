#include <iostream>
#include <string>

using namespace std;

int n;
int target_index;
string str;

int main()
{
    cin >> n;
    while (n--) {
        cin >> target_index >> str;
        cout << str.substr(0, target_index - 1) + str.substr(target_index) << '\n';
    }

    return 0;
}