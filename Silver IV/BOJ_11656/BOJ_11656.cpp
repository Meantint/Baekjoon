#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<string> answer;

int main()
{
    cin >> str;

    int str_size = str.size();
    for (int i = 0; i < str_size; ++i) {
        answer.push_back(str.substr(i));
    }

    sort(answer.begin(), answer.end());

    for (auto ans : answer) {
        cout << ans << '\n';
    }

    return 0;
}