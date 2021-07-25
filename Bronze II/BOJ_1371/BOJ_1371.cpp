#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MAX_SIZE 26

using namespace std;

vector<int> alpha(MAX_SIZE, 0);
string str;
string answer = "";

int main()
{
    while (getline(cin, str)) {
        for (auto ch : str) {
            if (ch == ' ') {
                continue;
            }
            else {
                ++alpha[ch - 'a'];
            }
        }
    }

    int max_count = -1;
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (max_count < alpha[i]) {
            max_count = alpha[i];

            answer.clear();
            answer.push_back('a' + i);
        }
        else if (max_count == alpha[i]) {
            answer.push_back('a' + i);
        }
    }

    cout << answer << '\n';

    return 0;
}