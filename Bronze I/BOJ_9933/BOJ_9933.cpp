#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int n;
string str;
set<string> s;

bool isPal(string temp)
{
    int first = 0, last = temp.size() - 1;
    while (first < last) {
        if (temp[first] != temp[last]) {
            return false;
        }
        ++first;
        --last;
    }

    return true;
}

int main()
{
    cin >> n;
    while (n--) {
        cin >> str;

        if (isPal(str)) {
            cout << str.size() << ' ' << str[str.size() / 2] << '\n';

            break;
        }
        if (s.find(str) != s.end()) {
            cout << str.size() << ' ' << str[str.size() / 2] << '\n';

            break;
        }
        s.insert(str);
        reverse(str.begin(), str.end());
        s.insert(str);
    }

    return 0;
}