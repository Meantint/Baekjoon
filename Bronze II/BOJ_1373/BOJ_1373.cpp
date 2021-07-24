#include <cmath>
#include <iostream>
#include <string>

using namespace std;

string str;
string answer = "";

int main()
{
    cin >> str;

    while (str.size() % 3 != 0) {
        str = '0' + str;
    }
    int size = str.size();
    for (int i = 0; i < size; i += 3) {
        int value = (str[i] - '0') * 4 + (str[i + 1] - '0') * 2 + str[i + 2] - '0';
        answer.push_back(value + '0');
    }

    cout << answer << '\n';

    return 0;
}