#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
    cin >> str;

    int size = str.size();
    while (size % 3 != 0) {
        ++size;
        str = '0' + str;
    }

    string answer = "";
    for (int i = 0; i < size; i += 3) {
        answer.push_back(((str[i] - '0') * 4 + (str[i + 1] - '0') * 2 + (str[i + 2] - '0')) + '0');
    }

    cout << answer << '\n';

    return 0;
}