#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
string answer = "";
vector<string> str_list;

int main()
{
    cin >> n;
    str_list.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> str_list[i];
    }

    int size = str_list[0].size();
    for (int i = 0; i < size; ++i) {
        bool isSame = true;

        char comp = str_list[0][i];
        for (int j = 1; j < n; ++j) {
            if (comp != str_list[j][i]) {
                isSame = false;
                break;
            }
        }

        if (isSame) {
            answer.push_back(comp);
        }
        else {
            answer.push_back('?');
        }
    }

    cout << answer << '\n';

    return 0;
}