#include <iostream>
#include <string>

using namespace std;

string str, check;

int main()
{
    cin >> str >> check;

    if (str.size() >= check.size()) {
        cout << "go" << '\n';
    }
    else {
        cout << "no" << '\n';
    }

    return 0;
}