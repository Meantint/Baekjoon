#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
    cin >> str;

    if (str[0] != '0') {
        cout << stoi(str) << '\n';
    }
    else {
        int num = 0;
        int size = str.size();
        if (str[1] != 'x') {
            for (int i = 1; i < size; ++i) {
                num *= 8;
                num += (str[i] - '0');
            }
        }
        else {
            for (int i = 2; i < size; ++i) {
                num *= 16;
                if ('a' <= str[i] && str[i] <= 'f') {
                    num += (str[i] - 'a' + 10);
                }
                else {
                    num += (str[i] - '0');
                }
            }
        }
        cout << num << '\n';
    }

    return 0;
}