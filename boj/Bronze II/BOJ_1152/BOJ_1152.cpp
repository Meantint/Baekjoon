#include <iostream>
#include <string>

using namespace std;

int answer = 0;
string str;
bool isBlank = true;

int main()
{
    getline(cin, str);

    for (auto &c : str) {
        // 이전 문자가 공백이었고
        if (isBlank) {
            // 이번 문자도 공백이라면
            if (c == ' ') {
                continue;
            }
            // 공백이 아니라면
            else {
                ++answer;
                isBlank = false;
            }
        }
        // 이전 문자가 공백이 아니었고
        else {
            // 이번 문자가 공백이라면
            if (c == ' ') {
                isBlank = true;
            }
            // 이번 문자가 공백이 아니라면
            else {
                continue;
            }
        }
    }
    cout << answer << '\n';

    return 0;
}