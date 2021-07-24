#include <iostream>
#include <string>
#include <vector>

using namespace std;

string answer = "";
vector<string> str;

int main()
{
    str.resize(5);

    int max_size = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> str[i];
        if (max_size < str[i].size()) {
            max_size = str[i].size();
        }
    }

    for (int i = 0; i < max_size; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i < str[j].size()) {
                answer.push_back(str[j][i]);
            }
        }
    }

    cout << answer << '\n';

    return 0;
}