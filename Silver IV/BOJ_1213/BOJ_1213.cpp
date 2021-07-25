#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int odd_count = 0;
string str;
string answer;
vector<int> alpha(26, 0);

int main()
{
    answer = "";
    string temp = "";
    string odd_str = "";

    cin >> str;
    for (auto ch : str) {
        ++alpha[ch - 'A'];
    }
    for (int i = 0; i < 26; ++i) {
        if (alpha[i] % 2 == 1) {
            ++odd_count;
            odd_str = 'A' + i;
        }
    }
    if (odd_count > 1) {
        cout << "I'm Sorry Hansoo" << '\n';
    }
    else {
        for (int i = 0; i < 26; ++i) {
            while (alpha[i] % 2 == 1 && alpha[i] != 1) {
                temp += ('A' + i);
                alpha[i] -= 2;
            }
            while (alpha[i] % 2 == 0 && alpha[i] != 0) {
                temp += ('A' + i);
                alpha[i] -= 2;
            }
        }

        answer += temp;
        reverse(temp.begin(), temp.end());
        answer += odd_str;
        answer += temp;

        cout << answer << '\n';
    }

    return 0;
}