#include <iostream>
#include <string>

using namespace std;

string str, check;

int main()
{
    int answer = 0;

    getline(cin, str);
    getline(cin, check);
    int range = str.size() - check.size() + 1;
    int check_size = check.size();
    for (int i = 0; i < range; ++i) {
        if (str.substr(i, check_size) == check) {
            ++answer;
            i += (check_size - 1);
        }
    }
    cout << answer << '\n';

    return 0;
}