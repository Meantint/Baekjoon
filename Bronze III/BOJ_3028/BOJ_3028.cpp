#include <iostream>
#include <string>

using namespace std;

int current_pos = 0;
string str;

int main()
{
    cin >> str;

    for (auto ch : str) {
        if (ch == 'A') {
            if (current_pos < 2) {
                current_pos = (current_pos + 1) % 2;
            }
        }
        else if (ch == 'B') {
            if (current_pos == 1) {
                current_pos = 2;
            }
            else if (current_pos == 2) {
                current_pos = 1;
            }
        }
        else if (ch == 'C') {
            if (current_pos == 0) {
                current_pos = 2;
            }
            else if (current_pos == 2) {
                current_pos = 0;
            }
        }
    }
    cout << current_pos + 1 << '\n';

    return 0;
}