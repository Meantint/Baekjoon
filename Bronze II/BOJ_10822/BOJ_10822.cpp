#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
    cin >> str;

    int answer = 0;
    string temp;
    for (auto ch : str) {
        if (ch == ',') {
            answer += stoi(temp);
            temp = "";
        }
        else {
            temp += ch;
        }
    }
    answer += stoi(temp);

    cout << answer << '\n';

    return 0;
}