#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (getline(cin, str)) {
        if (str == ".") {
            break;
        }

        stack<char> s;
        int size = str.size();
        for (int i = 0; i < size; ++i) {
            if (str[i] == '(' || str[i] == '[') {
                s.push(str[i]);
            }
            else if (str[i] == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    s.push('$');
                    break;
                }
            }
            else if (str[i] == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    s.push('$');
                    break;
                }
            }
            else {
                continue;
            }
        }
        if (s.empty()) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }

    return 0;
}