#include <bits/stdc++.h>

using namespace std;

string str;

int main()
{
    cin >> str;

    int sum = 0;
    bool isZero = false;
    int size = str.size();
    for (int i = 0; i < size; ++i) {
        if (str[i] == '0') {
            isZero = true;
        }
        sum += (str[i] - '0');
    }
    if (!isZero || sum % 3 != 0) {
        cout << "-1\n";
    }
    else {
        sort(str.begin(), str.end(), greater<char>());
        cout << str << '\n';
    }

    return 0;
}