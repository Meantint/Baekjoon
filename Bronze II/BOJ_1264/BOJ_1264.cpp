#include <iostream>
#include <string>

using namespace std;

string str;
string word_list = "aeiouAEIOU";

int main()
{
    while (getline(cin, str)) {
        int ret = 0;

        if (str == "#") {
            break;
        }
        for (auto ch : str) {
            if (word_list.find(ch) != string::npos) {
                ++ret;
            }
        }

        cout << ret << '\n';
    }

    return 0;
}