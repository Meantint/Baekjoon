#include <iostream>
#include <string>

using namespace std;

int n;
string str;

int main()
{
    cin >> n >> str;

    int a_count = 0, b_count = 0;
    for (auto ch : str) {
        if (ch == 'A') {
            ++a_count;
        }
        else {
            ++b_count;
        }
    }

    if (a_count == b_count) {
        cout << "Tie" << '\n';
    }
    else if (a_count < b_count) {
        cout << "B" << '\n';
    }
    else {
        cout << "A" << '\n';
    }

    return 0;
}