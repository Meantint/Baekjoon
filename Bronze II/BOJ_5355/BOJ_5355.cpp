#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
string str;

int main()
{
    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, str);

        vector<string> info;
        string temp = "";
        for (auto ch : str) {
            if (ch != ' ') {
                temp += ch;
            }
            else {
                info.push_back(temp);
                temp = "";
            }
        }
        info.push_back(temp);

        double num = stod(info[0]);
        int size = info.size();
        for (int i = 1; i < size; ++i) {
            if (info[i] == "@") {
                num *= (double)3;
            }
            else if (info[i] == "%") {
                num += (double)5;
            }
            else if (info[i] == "#") {
                num -= (double)7;
            }
        }

        cout << fixed;
        cout.precision(2);
        cout << num << '\n';
    }

    return 0;
}