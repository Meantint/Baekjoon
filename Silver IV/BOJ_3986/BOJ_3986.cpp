#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
int answer = 0;
string str;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        stack<char> s;
        cin >> str;

        for (auto ch : str) {
            if (s.empty()) {
                s.push(ch);
            }
            else {
                if (s.top() == ch) {
                    s.pop();
                }
                else {
                    s.push(ch);
                }
            }
        }

        if (s.empty()) {
            ++answer;
        }
    }

    cout << answer << '\n';

    return 0;
}