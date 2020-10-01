// 인터넷 도움 받아서 품.
// stack을 사용해야 한다는 것을 몰랐음.
// 처음에 문제에 나오는대로 하나하나 괄호 씌어서 풀려고 함.

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;

    string answer = "";
    stack<char> s;
    int size = str.size();
    for (int i = 0; i < size; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') answer += str[i];
        else {
            if (str[i] == '(') {
                s.push(str[i]);
            }
            else if (str[i] == '*' || str[i] == '/') {
                if (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                    answer += s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
            else if (str[i] == '+' || str[i] == '-') {
                while (!s.empty() && (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-')) {
                    answer += s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
            else if (str[i] == ')') {
                while (s.top() != '(') {
                    answer += s.top();
                    s.pop();
                }
                s.pop();
            }
        }
    }
    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }
    cout << answer << '\n';

    return 0;
}