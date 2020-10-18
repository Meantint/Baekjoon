#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    string answer = "";
    if (str[0] == 'A') answer += '4';
    else if (str[0] == 'B') {
        answer += '3';
    }
    else if (str[0] == 'C') {
        answer += '2';
    }
    else if (str[0] == 'D') {
        answer += '1';
    }
    else if (str[0] == 'F') {
        cout << "0.0" << '\n';

        return 0;
    }
    answer += '.';
    if (str[1] == '+') answer += '3';
    else if (str[1] == '0') {
        answer += '0';
    }
    else if (str[1] == '-') {
        answer[0] = ((int)(answer[0] - '0') - 1) + '0';
        answer += '7';
    }
    cout << answer << '\n';

    return 0;
}