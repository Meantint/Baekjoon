#include <iostream>
#include <string>

using namespace std;

string str;
string word = "UCPC";

int main()
{
    getline(cin, str);

    bool answer = true;

    int str_index = 0;
    int index = 0;
    while (1) {
        if (str.find(word[index], str_index) != string::npos) {
            str_index = str.find(word[index], str_index);
            ++index;
            if (index == 4) {
                break;
            }
        }
        else {
            answer = false;
            break;
        }
    }

    cout << "I ";
    if (answer) {
        cout << "love ";
    }
    else {
        cout << "hate ";
    }
    cout << "UCPC\n";

    return 0;
}