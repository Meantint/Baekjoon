#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "";
    string answer = "";

    cin >> str;
    if (str == "0") {
        cout << str << '\n';

        return 0;
    }
    int size = str.size();
    for (int i = 0; i < size; ++i) {
        int num = str[i] - '0';
        string tmp = "";
        int idx = 0;
        while (idx != 3) {
            if (num % 2 == 1) {
                tmp = "1" + tmp;
            }
            else {
                tmp = "0" + tmp;
            }
            num /= 2;
            ++idx;
        }
        answer += tmp;
    }
    int idx = 0;
    while (answer[idx] == '0') {
        ++idx;
    }
    cout << answer.substr(idx) << '\n';

    return 0;
}