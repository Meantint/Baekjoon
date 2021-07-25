#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string str;
string answer;

int main()
{
    getline(cin, str);

    string answer = "";
    string temp = "";
    bool inTag = false;
    for (auto s : str) {
        if (inTag) {
            answer += s;
            if (s == '>') {
                inTag = false;
            }
        }
        else {
            if (s == '<') {
                inTag = true;

                reverse(temp.begin(), temp.end());
                answer += temp;
                answer += '<';

                temp = "";
            }
            else if (s == ' ') {
                reverse(temp.begin(), temp.end());

                answer += temp;
                answer += ' ';

                temp = "";
            }
            else {
                temp += s;
            }
        }
    }
    if (temp.back() != '>') {
        reverse(temp.begin(), temp.end());

        answer += temp;
    }

    cout << answer << '\n';

    return 0;
}