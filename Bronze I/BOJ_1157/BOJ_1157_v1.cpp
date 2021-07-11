#include <iostream>
#include <vector>

using namespace std;

string s;
vector<int> alpha(26, 0);
vector<int> answer;

int main()
{
    cin >> s;

    for (auto c : s) {
        if ('a' <= c && c <= 'z') {
            ++alpha[c - 'a'];
        }
        else if ('A' <= c && c <= 'Z') {
            ++alpha[c - 'A'];
        }
    }

    answer.push_back(0);
    for (int i = 1; i < 26; ++i) {
        int max_value = alpha[answer.back()];
        int current_value = alpha[i];

        if (max_value < current_value) {
            answer.clear();
            answer.push_back(i);
        }
        else if (max_value == current_value) {
            answer.push_back(i);
        }
    }

    if (answer.size() == 1) {
        cout << (char)('A' + answer[0]) << '\n';
    }
    else {
        cout << '?' << '\n';
    }

    return 0;
}