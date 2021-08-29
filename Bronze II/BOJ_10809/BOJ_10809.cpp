#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<int> alpha(26, -1);

int main()
{
    cin >> str;

    int size = str.size();
    for (int i = 0; i < size; ++i) {
        if (alpha[str[i] - 'a'] == -1) {
            alpha[str[i] - 'a'] = i;
        }
    }
    for (int i = 0; i < 26; ++i) {
        cout << alpha[i] << '\n';
    }

    return 0;
}