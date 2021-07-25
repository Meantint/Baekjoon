#include <iostream>
#include <string>

using namespace std;

string str;
string answer;

int main()
{
    answer = "";
    cin >> str;

    for (auto s : str) {
        if ('A' <= s && s <= 'C') {
            answer.push_back((char)(s + 23));
        }
        else {
            answer.push_back((char)(s - 3));
        }
    }

    cout << answer << '\n';

    return 0;
}