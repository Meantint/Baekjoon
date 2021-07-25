#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
    int count = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> str;
        if (str.find("FBI") != string::npos) {
            cout << i + 1 << ' ';
            ++count;
        }
    }
    if (count == 0) {
        cout << "HE GOT AWAY!" << '\n';
    }
    else {
        cout << '\n';
    }

    return 0;
}