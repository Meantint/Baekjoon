#include <iostream>
#include <string>
#include <vector>

#define MAX_SIZE 26

using namespace std;

string str;
vector<bool> alpha(MAX_SIZE, false);

int main()
{
    string delete_str = "CAMBRIDGE";
    for (auto ds : delete_str) {
        alpha[ds - 'A'] = true;
    }

    cin >> str;

    string answer = "";
    for (auto s : str) {
        if (!alpha[s - 'A']) {
            answer.push_back(s);
        }
    }

    cout << answer << '\n';

    return 0;
}