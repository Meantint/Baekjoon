#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s1, s2;
stack<char> s;

bool isSame()
{
    string temp;
    int s2Size = s2.size();
    for (int i = 0; i < s2Size; ++i) {
        temp += s.top();
        s.pop();
    }
    reverse(temp.begin(), temp.end());
    if (temp == s2) {
        return true;
    }
    else {
        for (int i = 0; i < s2Size; ++i) {
            s.push(temp[i]);
        }
        return false;
    }
}

int main()
{
    cin >> s1 >> s2;
    int s1Size = s1.size();
    int s2Size = s2.size();
    for (int i = 0; i < s1Size; ++i) {
        s.push(s1[i]);
        while (!s.empty() && s.top() == s2[s2Size - 1] && s.size() >= s2Size && isSame()) {
        }
    }
    string answer = "";
    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }
    if (answer.empty()) {
        cout << "FRULA\n";
    }
    else {
        reverse(answer.begin(), answer.end());
        cout << answer << '\n';
    }

    return 0;
}