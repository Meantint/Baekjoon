#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int tc;
string str;

int main()
{
    cin >> tc;
    cin.ignore();  // getline 하기 전에 cin으로 받은 후 있는 개행 문자를 제거해준다.
    while (tc--) {
        str = "";
        getline(cin, str);

        string temp = "";
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') {
                reverse(temp.begin(), temp.end());
                cout << temp << ' ';
                temp = "";
            }
            else {
                temp.push_back(str[i]);
            }
        }
        reverse(temp.begin(), temp.end());
        cout << temp << '\n';
    }

    return 0;
}