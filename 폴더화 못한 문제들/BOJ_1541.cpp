#include <bits/stdc++.h>

using namespace std;

string str;

int main()
{
    cin >> str;

    vector<int> save;
    int num = 0;
    bool isPlus = true;
    int size = str.size();
    for (int i = 0; i < size; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            num *= 10;
            num += (str[i] - '0');
        }
        else {
            if (isPlus == true && str[i] == '-') {
                save.push_back(num);
                num = 0;
                isPlus = false;
            }
            else if (isPlus == true && str[i] == '+') {
                save.push_back(num);
                num = 0;
            }
            else {
                save.push_back(num * -1);
                num = 0;
            }
        }
    }
    if (isPlus) {
        save.push_back(num);
    }
    else {
        save.push_back(num * -1);
    }

    int answer = 0;
    size = save.size();
    for (int i = 0; i < size; ++i) {
        answer += save[i];
    }
    cout << answer << '\n';

    return 0;
}